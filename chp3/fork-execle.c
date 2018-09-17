#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	char** env[] = {"USER=hh", "PATH=/home/abc", NULL};
	execle("/bin/ls", "ls", "-l", "/etc", NULL, env);
	return 0;
}
