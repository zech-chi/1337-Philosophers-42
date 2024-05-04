/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:49:05 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 16:01:56 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_create(t_table *table)
{
	table->mtx_forks = malloc(sizeof(pthread_mutex_t) * table->n_philosophers);
	if (!table->mtx_forks)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_forks_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		if (pthread_mutex_init(table->mtx_forks + i, NULL))
		{
			ft_put_error(MUTEX_CREAT_ERROR);
			ft_forks_destroy(table, i);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_forks_destroy(t_table *table, int size)
{
	int	i;
	int	error;

	error = SUCCESS;
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(table->mtx_forks + i))
			error = FAILED;
		i++;
	}
	if (error)
		ft_put_error(MUTEX_DESTROY_ERROR);
	return (error);
}

void	ft_forks_up(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->mtx_forks)[philo->id_left_fork];
	right_fork = &(philo->table->mtx_forks)[philo->id_right_fork];
	if (pthread_mutex_lock(left_fork))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	else
		ft_put_action(ft_time(philo), philo, TAKE_FORK);
	if (pthread_mutex_lock(right_fork))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	else
		ft_put_action(ft_time(philo), philo, TAKE_FORK);
}

void	ft_forks_down(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->mtx_forks)[philo->id_left_fork];
	right_fork = &(philo->table->mtx_forks)[philo->id_right_fork];
	if (pthread_mutex_unlock(left_fork))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	if (pthread_mutex_unlock(right_fork))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
}
