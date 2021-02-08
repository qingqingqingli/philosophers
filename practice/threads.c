//
// Created by qli on 08/02/2021.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* myturn(void * arg)
{
	int *iptr = (int *)malloc(sizeof(int));
	*iptr = 5;
	for(int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("My Turn! %d\n", i);
		(*iptr)++;
	}
	// return a value when the function is done
	return iptr;
}

void yourturn()
{
	for(int i = 0; i < 3; i++)
	{
		sleep(2);
		printf("Your Turn! %d\n", i);
	}
}

int main()
{
	pthread_t newthread;
	int result;
	pthread_create(&newthread, NULL, myturn, NULL);
//	myturn();
	yourturn();

	// to make sure that the thread will finish before the main returns, you need to join the thread
	// it also allows us to get the value from the function
	pthread_join(newthread, &result);
	printf("thread is done: v = %d\n", result);
	free(result);
	return 0;
}