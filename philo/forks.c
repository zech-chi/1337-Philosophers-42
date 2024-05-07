/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:49:05 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/07 17:44:25 by zech-chi         ###   ########.fr       */
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
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_forks_destroy(t_table *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(table->mtx_forks + i))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

void	ft_forks_up(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->mtx_forks)[philo->id_left_fork];
	right_fork = &(philo->table->mtx_forks)[philo->id_right_fork];
	if (ft_mtx_lock(philo->table, left_fork) == SUCCESS)
		ft_put_action(ft_time_1(philo->table), philo, TAKE_FORK);
	if (ft_mtx_lock(philo->table, right_fork) == SUCCESS)
		ft_put_action(ft_time_1(philo->table), philo, TAKE_FORK);
}

void	ft_forks_down(t_philo *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &(philo->table->mtx_forks)[philo->id_left_fork];
	right_fork = &(philo->table->mtx_forks)[philo->id_right_fork];
	ft_mtx_unlock(philo->table, left_fork);
	ft_mtx_unlock(philo->table, right_fork);
}
