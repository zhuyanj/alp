# $@ 表示一个规则中的目标
# $^ 表示规则中所有的先决条件
# $< 表示规则中的第一个先决条件  
# $(MAKECMDGOALS 表示用户输入的目标
# $(CURDIR) 表示当前目录
.PHONY:all clean

MKDIR = mkdir
CC = gcc
RM = rm
RMFLAGS= -rf

DIR_OBJS = objs
DIR_EXES = exes
DIR_DEPS = deps

DIRS = $(DIR_OBJS) $(DIR_EXES) $(DIR_DEPS)

EXE = simple
EXE := $(addprefix $(DIR_EXES)/, $(EXE))
SRCS=$(wildcard *.c)
#OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(DIR_OBJS)/, $(OBJS))
DEPS = $(SRCS:.c=.dep)
DEPS := $(addprefix $(DIR_DEPS)/, $(DEPS))

ifeq ($(wildcard $(DIR_OBJS)), )
DEP_DIR_OBJS := $(DIR_OBJS)
endif

ifeq ($(wildcard $(DIR_EXES)), )
DEP_DIR_EXES := $(DIR_EXES)
endif

ifeq ($(wildcard $(DIR_DEPS)), )
DEP_DIR_DEPS := $(DIR_DEPS)
endif

all: $(EXE)

sinclude $(DEPS)

$(DIRS):
	echo $(DIRS)
	$(MKDIR) $@

$(EXE):$(DEP_DIR_EXES) $(OBJS)
	$(CC) -o $@ $(filter %.o, $^)
$(DIR_OBJS)/%.o : $(DEP_DIR_OBJS) %.c
	$(CC) -o $@ -c $(filter %.c, $^)
$(DIR_DEPS)/%.dep:$(DEP_DIR_DEPS) %.c
	@echo "Creating $@ ..."
	@set -e;\
	$(RM) $(RMFLAGS) $@.tmp;\
	$(CC) -E -MM $(filter %.c, $^) > $@.tmp;\
	sed 's,\(.*\)\.o[:]*,objs/\1.o:,g' <$@.tmp >$@;\
	$(RM) $(RMFLAGS) $@.tmp

.PHONY: clean
clean:
	$(RM) $(RMFLAGS) $(EXE) $(DIRS)

echo:
	@echo $(OBJS)

.PHONY:auto_val
auto_val:first second third
	@echo "\$$@ = $@"
	@echo "$$^ = $^"
	@echo "$$< = $<"
first second third:

.PHONY: makecmdgoals @
makecmdgoals @:
	@echo "\$$@ = $@"
	@echo "MAKECMDGOALS = $(MAKECMDGOALS)"
	@echo "CURDIR = $(CURDIR)"
