/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/02 19:13:25 by zech-chi         ###   ########.fr       */
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
	else if (error_id == MUTEX_LOCK_ERROR)
		ft_put_on_stderr("Error: failed to lock mutex\n");
	else if (error_id == MUTEX_UNLOCK_ERROR)
		ft_put_on_stderr("Error: failed to unlock mutex\n");
}

void	ft_free_them_all(t_data *table)
{
	free(table->philosophers);
	free(table->forks);
	table->philosophers = NULL;
	table->forks = NULL;
}

void	ft_put_action(time_t time, t_philo *philo, int action)
{
	pthread_mutex_lock(&(philo->table->put_action_mtx));
	if (action == TAKE_FORK && !ft_stop_get(philo->table))
		printf("%ld %d has taken a fork\n", time, philo->id + 1);
	else if (action == EAT && !ft_stop_get(philo->table))
		printf("%ld %d is eating\n", time, philo->id + 1);
	else if (action == SLEEP && !ft_stop_get(philo->table))
		printf("%ld %d is sleeping\n", time, philo->id + 1);
	else if (action == THINK && !ft_stop_get(philo->table))
		printf("%ld %d is thinking\n", time, philo->id + 1);
	else if (action == DIED && !ft_stop_get(philo->table))
		printf("%ld %d died\n", time, philo->id + 1);
	pthread_mutex_unlock(&(philo->table->put_action_mtx));
}



