/*日志键值共有，每个线程的专有日志数据区独立。使用pthread_getspecific(pthread_key_t key)获取对应的日志数区
**使用pthread_setspecific(pthread_key_t key, void*)将键值和专有数据区绑定。
**使用pthread_key_create(pthread_key_t *key, void(*func)(void*))将key和清理函数func绑定，
**线程退出时，键值key对应的数据退休自动调用该函数清除
*/
#include <malloc.h>
#include <pthread.h>
#include <stdio.h>

static pthread_key_t thread_log_key;

void write_to_thread_log(const char* message)
{
	FILE* thread_log = (FILE*)pthread_getspecific(thread_log_key);
	fprintf(thread_log, "%s\n", message);
}

void close_thread_log(void* thread_log)
{
	fclose((FILE*)thread_log);
}

void* thread_function(void* args)
{
	char thread_log_filename[20];
	FILE* thread_log;

	sprintf(thread_log_filename, "thread%d.log", (int)pthread_self());
	thread_log = fopen(thread_log_filename, "w");
	pthread_setspecific(thread_log_key, thread_log);
	write_to_thread_log("Thread starting.");
	return NULL;
}

int main(void)
{
	int i;
	pthread_t threads[5];

	pthread_key_create(&thread_log_key, close_thread_log);
	for(i = 0; i < 5; ++i)
		pthread_create(&(threads[i]), NULL, thread_function, NULL);
	for(i = 0; i < 5; ++i)
		pthread_join(threads[i], NULL);
	return 0;
}
