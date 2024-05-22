/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:52:02 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 10:42:20 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_one_philo_routine(void *arg)
{
	t_philo			*philo;
	pthread_mutex_t	*left_fork;

	philo = (t_philo *)arg;
	left_fork = &(philo->table->mtx_forks)[philo->id_left_fork];
	if (ft_mtx_lock(philo->table, left_fork) == SUCCESS)
		ft_put_action(ft_time_1(philo->table, ft_time_cur_ms()), \
		philo, TAKE_FORK);
	ft_mtx_unlock(philo->table, left_fork);
	ft_time_sleep_ms(ft_mtx_get_time_to_die(philo->table));
	ft_dead(philo);
	return (NULL);
}

int	ft_one_philo(t_table *table)
{
	pthread_t	*id_thread_philo;

	id_thread_philo = &(table->philos)[0].id_thread;
	if (pthread_create(id_thread_philo, NULL, \
	ft_one_philo_routine, &(table->philos)[0]))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	if (pthread_join(*id_thread_philo, NULL))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_simulation(t_table *table)
{
	pthread_t	*id_thread_philo;
	pthread_t	id_thread_monitor;
	int			i;

	if (ft_mtx_get_n_philosophers(table) == 1)
		return (ft_one_philo(table));
	if (ft_monitor_thread_create(table, &id_thread_monitor))
		return (FAILED);
	i = -1;
	while (++i < ft_mtx_get_n_philosophers(table))
	{
		id_thread_philo = &(table->philos)[i].id_thread;
		if (pthread_create(id_thread_philo, NULL, \
		ft_routine, &(table->philos)[i]))
		{
			return (ft_mtx_set_stop(table), FAILED);
		}
	}
	if (ft_philos_detach(table))
		return (FAILED);
	if (ft_monitor_thread_join(table, id_thread_monitor))
		return (FAILED);
	return (SUCCESS);
}
