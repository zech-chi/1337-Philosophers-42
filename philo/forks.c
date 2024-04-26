/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:16:51 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/26 14:23:48 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_create(t_data *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philosopher);
	if (!table->forks)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_forks_init(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosopher)
	{
		if (pthread_mutex_init(table->forks + i, NULL))
		{
			ft_put_error(MUTEX_CREAT_ERROR);
			ft_forks_destroy(table, i);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_forks_destroy(t_data *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(table->forks + i))
		{
			ft_put_error(MUTEX_DESTROY_ERROR);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

void	ft_forks_up(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->forks)[philo->left_fork_id];
	right_fork = &(philo->table->forks)[philo->right_fork_id];
	if (pthread_mutex_lock(left_fork))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		philo->table->error = 1;
	}
	ft_put_action(ft_time(philo), philo->id, TAKE_FORK);
	if (pthread_mutex_lock(right_fork))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		philo->table->error = 1;
	}
	ft_put_action(ft_time(philo), philo->id, TAKE_FORK);
}

void	ft_forks_down(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->forks)[philo->left_fork_id];
	right_fork = &(philo->table->forks)[philo->right_fork_id];
	if (pthread_mutex_unlock(left_fork))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		philo->table->error = 1;
	}
	if (pthread_mutex_unlock(right_fork))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		philo->table->error = 1;
	}
}
