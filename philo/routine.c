/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:56:35 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/05 23:16:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	if (ft_mtx_get_stop(philo->table))
		return ;
	ft_put_action(ft_time_1(philo->table), philo, EAT);
	ft_mtx_set_time_last_meal(philo);
	ft_mtx_set_eat_n_meals(philo);
	ft_time_sleep_ms(ft_mtx_get_time_to_eat(philo->table));
}

static void	ft_sleep(t_philo *philo)
{
	if (ft_mtx_get_stop(philo->table))
		return ;
	ft_put_action(ft_time_1(philo->table), philo, SLEEP);
	ft_time_sleep_ms(ft_mtx_get_time_to_sleep(philo->table));
}

static void	ft_think(t_philo *philo)
{
	if (ft_mtx_get_stop(philo->table))
		return ;
	ft_put_action(ft_time_1(philo->table), philo, THINK);
}

static void	*ft_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2)
		ft_time_sleep_ms(50);
	while (ft_mtx_get_stop(philo->table) == 0)
	{
		ft_forks_up(philo);
		ft_eat(philo);
		ft_forks_down(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (ft_mtx_get_eat_n_meals(philo) == ft_mtx_get_max_meals(philo->table))
			break;
	}
	return (NULL);
}

int	ft_simulation(t_table *table)
{
	pthread_t	*id_thread_philo;
	//pthread_t	id_thread_monitor;
	int			i;
	int			n_philosopher;

	n_philosopher = ft_mtx_get_n_philosophers(table);
	i = 0;
	while (i < n_philosopher)
	{
		id_thread_philo = &(table->philos)[i].id_thread;
		if (pthread_create(id_thread_philo, NULL, ft_routine, &(table->philos)[i]))
		{
			ft_put_error(CREAT_THREAD_ERROR);
			ft_mtx_set_stop(table);
			return (FAILED);
		}
		i++;
	}
	if (ft_philos_join(table))
		return (FAILED);
	return (SUCCESS);
}
