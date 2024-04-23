#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*f(void *arg)
{
	printf("%d\n", primes[*((int *)arg)]);
	return (NULL);
}

int	main(void)
{
	pthread_t	th[10];
	int index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(th + i, NULL, &f, index + i))
			return (1);
	}
	for (int i = 0; i < 10; i++)
	{
		if (pthread_join(*(th + i), NULL))
			return (1);
	}
	
	return (0);
}
