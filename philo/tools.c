/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 18:20:01 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_put_on_stderr(char *msg)
{
	int	i;

	if (!msg)
		return ;
	i = 0;
	while (msg[i])
	{
		write(2, msg + i, 1);
		i++;
	}
}

void	ft_put_error(int error_id)
{
	if (error_id == PARSING_ERROR)
		ft_put_on_stderr("Error: invalid arguments\n");
	else if (error_id == MALLOC_ERROR)
		ft_put_on_stderr("Error: failed to allocate memory\n");
	else if (error_id == CREAT_THREAD_ERROR)
		ft_put_on_stderr("Error: failed to create thread\n");
	else if (error_id == JOIN_THREAD_ERROR)
		ft_put_on_stderr("Error: failed to join thread\n");
	else if (error_id == MUTEX_CREAT_ERROR)
		ft_put_on_stderr("Error: failed to create mutex\n");
	else if (error_id == MUTEX_DESTROY_ERROR)
		ft_put_on_stderr("Error: failed to destroy mutex\n");
}

void	ft_free_them_all(t_data *table)
{
	free(table->philosophers);
	free(table->forks);
	table->philosophers = NULL;
	table->forks = NULL;
}

void	ft_put_action(time_t time, int philo_id, int action)
{
	if (action == TAKE_FORK)
		printf("%ld %d has taken a fork\n", time, philo_id + 1);
	else if (action == EAT)
		printf("%ld %d is eating\n", time, philo_id + 1);
	else if (action == SLEEP)
		printf("%ld %d is sleeping\n", time, philo_id + 1);
	else if (action == THINK)
		printf("%ld %d is thinking\n", time, philo_id + 1);
	else if (action == DIED)
		printf("%ld %d died\n", time, philo_id + 1);
}

size_t	ft_get_time(void)
{
	struct timeval	tv;
	size_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}
