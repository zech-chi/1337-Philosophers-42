#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*f(void *x)
{
	(*(int *)x)++;
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	int	x;

	x = 0;
	if (pthread_create(&t1, NULL, &f, &x))
		return (1);
	if (pthread_create(&t2, NULL, &f, &x))
		return (1);
	if (pthread_join(t1, NULL))
		return (1);
	if (pthread_join(t2, NULL))
		return (1);
	printf("x = %d\n", x);
	return (0);
}