#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice()
{
	int	x = 1 + rand() % 6;
	int *res = malloc(sizeof(int));
	*res = x;
	return ((void *)res);
}

int	main(void)
{
	srand(time(NULL));
	pthread_t th;
	int	*res;
	if (pthread_create(&th, NULL, &roll_dice, NULL))
		return (1);
	if (pthread_join(th, (void **)&res))
		return (1);
	printf("res = %d\n", *res);
	free(res);
	return (0);
}
