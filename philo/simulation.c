/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:52:02 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/07 15:01:20 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	*ft_one_philo_routine(void *arg)
//{
//	t_philo *philo;

//	philo = (t_philo *)arg;
//	if (ft_mtx_lock(philo->table, left_fork) == SUCCESS)
//		ft_put_action(ft_time_1(philo->table), philo, TAKE_FORK);
	
//}

//int	ft_one_philo(t_table *table)
//{
//	pthread_t	*id_thread_philo;

//	id_thread_philo = &(table->philos)[0].id_thread;
//	if (pthread_create(id_thread_philo, NULL, ft_one_philo_routine, &(table->philos)[i]))
//	{
//		ft_put_error(CREAT_THREAD_ERROR);
//		ft_mtx_set_stop(table);
//		return (FAILED);
//	}
//	if (pthread_join(*id_thread_philo, NULL))
//	{
//		ft_put_error(JOIN_THREAD_ERROR);
//		ft_mtx_set_stop(table);
//		return (FAILED);
//	}
//}

int	ft_simulation(t_table *table)
{
	pthread_t	*id_thread_philo;
	pthread_t	id_thread_monitor;
	int			i;

	if (ft_monitor_thread_create(table, &id_thread_monitor))
		return (FAILED);
	//if (n_philosopher == 1)
	//	return (ft_one_philo(table));
	i = -1;
	while (++i < ft_mtx_get_n_philosophers(table))
	{
		id_thread_philo = &(table->philos)[i].id_thread;
		if (pthread_create(id_thread_philo, NULL, ft_routine, &(table->philos)[i]))
		{
			ft_put_error(CREAT_THREAD_ERROR);
			ft_mtx_set_stop(table);
			return (FAILED);
		}
	}
	if (ft_philos_join(table))
		return (FAILED);
	if (ft_monitor_thread_join(table, id_thread_monitor))
		return (FAILED);
	return (SUCCESS);
}
