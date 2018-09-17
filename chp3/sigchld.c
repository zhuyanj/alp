#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

sig_atomic_t child_exit_status;

void clean_up_child_process(int signal_number)
{
	int status = 0;
	wait(&status);
	child_exit_status = status;
	printf("1:%d\n", child_exit_status);
}

int main()
{
	struct sigaction sigchld_action;
	memset(&sigchld_action, 0, sizeof(sigchld_action));
	sigchld_action.sa_handler = &clean_up_child_process;
	sigaction(SIGCHLD, &sigchld_action, NULL);
	
	pid_t child_pid;

        child_pid = fork();
        if (child_pid > 0) {
                 /*这是父进程，休眠一分钟。*/
                 sleep(60);
        } else {
                /*这是子进程，立刻退出。*/
                exit(1);
        }
	printf("%d\n", child_exit_status);
	
	return 0;
}
