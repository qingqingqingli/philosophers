//
// Created by qli on 19/02/2021.
//

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void 	*action(void *arg)
{
	sem_t *semaphore;
	semaphore = arg;

	// wait & acquire the lock
	sem_wait(semaphore);
	sem_wait(semaphore);
	printf("ENTER...\n");

	// critical section
	usleep(40000);

	// signal
	printf("FINISH SLEEPING...\n");
	sem_post(semaphore);
	sem_post(semaphore);

	return (NULL);
}

int	main(void)
{

	pthread_t 	t1, t2;

	sem_t *semaphore = sem_open("semaphore", O_CREAT, 0644, 1);
	// prevent semaphore from running forever
	// if crash happens during execution
	sem_unlink("semaphore");
	pthread_create(&t1, NULL, action, semaphore);
	pthread_create(&t2, NULL, action, semaphore);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sem_destroy(semaphore);
	return (0);
}