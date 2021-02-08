#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 500000
long long sum = 0;

// need to identify the critical section
// the critical section happens when you have shared data

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_thread(void *arg)
{
	int offset = *(int *)arg;
	for(int i =  0; i < NUM_LOOPS; i++)
	{
		// sum is the shared resource here, which needs to be protected
		// start critical section
		pthread_mutex_lock(&mutex);

		// now the sum as a shared resource is protected by the mutex
		sum += offset;

		// end critical section
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int main(void)
{
	// Spawn threads
	pthread_t id1;
	int offset1 = 1;
	pthread_create(&id1, NULL, counting_thread, &offset1);

	pthread_t id2;
	int offset2 = -1;
	pthread_create(&id2, NULL, counting_thread, &offset2);

	// Wait for threads to finish
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	printf("sum = %lld\n", sum);
	return (0);
}