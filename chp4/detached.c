#include <pthread.h>
#include <stdio.h>


void* thread_function(void* thread_arg)
{
	fputc('x', stderr);	
	return NULL;
}

int main(void)
{
	pthread_attr_t attr;
	pthread_t thread;
	
	pthread_attr_init(&attr);
//	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	pthread_create(&thread, &attr, &thread_function, NULL);
	pthread_attr_destroy(&attr);

	pthread_join(thread, NULL);
	return 0;
}
