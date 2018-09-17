#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;
	
	printf("the main program process ID is %d\n", getpid());

	child_pid = fork();
	if (child_pid) {
		printf("this is the parent process, with id %d\n", getpid());
		printf("the child's process ID is %d\n", child_pid);
		while(1);//没有这行时，else中的父进程id可能为1，这是因为父进程可能已经结束，子进程挂在init进程下了
	} else {
		printf("this is the child process, with id %d\n", getpid());
		printf("the parent process ID is %d\n", getppid());
	}

	return 0;
}
