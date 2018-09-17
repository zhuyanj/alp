#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	execlp("ls", "ls", "-l", "/etc", NULL);

	return 0;
}
