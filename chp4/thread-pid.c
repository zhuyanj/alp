#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void* thread_function(void* arg)
{
	fprintf(stderr, "child thread pid is %d\n", (int)gettid());
	while(1);
	return NULL;
}

int main()
{
	pthread_t thread;
	fprintf(stderr, "main thread pid is %d\n", (int)gettid());
	pthread_create(&thread, NULL, &thread_function, NULL);
	fprintf(stderr, "child thread pid is %d\n",(int)thread); 
	while(1);
	return 0;
}
