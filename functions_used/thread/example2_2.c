#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*f()
{
	printf("pid = %d\n", getpid());
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &f, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &f, NULL))
		return (1);
	if (pthread_join(t1, NULL))
		return (1);
	if (pthread_join(t2, NULL))
		return (1);
	return (0);
}