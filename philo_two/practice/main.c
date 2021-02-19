//
// Created by qli on 19/02/2021.
//

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t 		semaphore;

void 	*action(void *arg)
{
	// wait & acquire the lock
	sem_wait(&semaphore);
	printf("ENTER...\n");

	// critical section
	usleep(40000);

	// signal
	printf("FINISH SLEEPING...\n");
	sem_post(&semaphore);

	return (NULL);
}

int	main(void)
{

	pthread_t 	t1, t2;

	sem_init(&semaphore, 0, 1);
	pthread_create(&t1, NULL, action, NULL);
	pthread_create(&t2, NULL, action, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sem_destroy(&semaphore);
	return (0);
}