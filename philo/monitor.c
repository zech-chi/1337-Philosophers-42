/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:05 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:12:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor_thread_create(t_table *table, pthread_t *id_thread_monitor)
{
	if (pthread_create(id_thread_monitor, NULL, &ft_monitor_job, table))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_monitor_thread_join(t_table *table, pthread_t id_thread_monitor)
{
	if (pthread_join(id_thread_monitor, NULL))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
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
		usleep(250);
	}
	return (NULL);
}
