#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	main(void)
{
	int	pid;
	int	x;

	x = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		x++;
	printf("x = %d\n", x);
	if (pid != 0)
		wait(NULL);
	return (0);
}