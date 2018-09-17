#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		execl("/bin/ls", "ls", "-l", "/etc", NULL);
	} else {
		printf("parent process\n");
	}
	return 0;
}
