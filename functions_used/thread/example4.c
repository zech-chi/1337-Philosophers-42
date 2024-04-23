#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*f(void *x)
{
	for (int i = 0; i < 100000; i++)
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
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);
	printf("x = %d\n", x);
	return (0);
}
