#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("origin is %d\n", getpid());
	printf("origin p is %d\n", getppid());

	pid_t pid;
	pid = fork();
	int a;
	printf("input a is...\n");
	scanf("%d", &a);
	if(pid > 0) {
		printf("parent is %d\n", getpid());
	} else if(pid == 0) {
		printf("child is %d\n", getpid());
		printf("child's parent is %d\n", getppid());
	}
	return 0;
}
