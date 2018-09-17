#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int ret;
	ret = system("ls -l /");
	printf("ret=%d\n", ret);
	return ret;
}
