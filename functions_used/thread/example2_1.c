#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	printf("pid = %d\n", getpid());
	if (pid != 0)
		wait(NULL);
	return (0);
}