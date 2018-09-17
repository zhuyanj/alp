#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct char_print_parms
{
	char character;
	int count;
};

void* char_print(void* param)
{
	struct char_print_parms *p = (struct char_print_parms*)param;
	int i;

	for (i = 0; i < p->count; ++i)
		fputc(p->character, stderr);
	return NULL;
}

int main()
{
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;

	thread1_args.character = 'x';
	thread1_args.count = 3;
	pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

	thread1_args.character = 'o';
	thread1_args.count = 2;
	pthread_create(&thread2_id, NULL, &char_print, &thread2_args);
//	pthread_join(thread1_id, NULL);
//	pthread_join(thread2_id, NULL);
	sleep(10);
	return 0;
}
