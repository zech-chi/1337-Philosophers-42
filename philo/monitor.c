/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:05 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/07 15:05:01 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor_thread_create(t_table *table, pthread_t *id_thread_monitor)
{
	if (pthread_create(id_thread_monitor, NULL, &ft_monitor_job, table))
	{
		ft_put_error(CREAT_THREAD_ERROR);
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_monitor_thread_join(t_table *table, pthread_t id_thread_monitor)
{
	if (pthread_join(id_thread_monitor, NULL))
	{
		ft_put_error(JOIN_THREAD_ERROR);
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}

static void	ft_dead(t_philo *philo)
{
	if (ft_mtx_get_stop(philo->table))
		return ;
	ft_put_action(ft_time_1(philo->table), philo, DIED);
	ft_mtx_set_stop(philo->table);
}

void	*ft_monitor_job(void *arg)
{
	t_table	*table;
	int		i;
	int		count_full_philos;
	int		max_meals;

	table = (t_table *)arg;
	max_meals = ft_mtx_get_max_meals(table);
	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		count_full_philos = 0;
		while (++i < ft_mtx_get_n_philosophers(table))
		{
			if (ft_mtx_get_eat_n_meals(&(table->philos)[i]) == max_meals)
				count_full_philos++;
			else if (ft_time_2(&(table->philos)[i]) > \
			(size_t)ft_mtx_get_time_to_die(table))
				return (ft_dead(&(table->philos)[i]), NULL);
		}
		if (count_full_philos == ft_mtx_get_n_philosophers(table))
			break ;
		usleep(50);
	}
	return (NULL);
}
