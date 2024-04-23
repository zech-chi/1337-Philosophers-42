#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t	mutex;

void	*f(void *x)
{
	for (int i = 0; i < 10000000; i++)
	{
		pthread_mutex_lock(&mutex);
		(*(int *)x)++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	th[6];
	int	x;

	x = 0;
	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 6; i++)
	{
		if (pthread_create(th + i, NULL, &f, &x) != 0)
			return (1);
	}
	for (int i = 0; i < 6; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
	}
	printf("x = %d\n", x);
	pthread_mutex_destroy(&mutex);
	return (0);
}
