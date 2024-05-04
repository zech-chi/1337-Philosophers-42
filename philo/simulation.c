/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 10:46:28 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	if (ft_stop_get(philo->table))
		return ;
	ft_put_action(ft_time(philo), philo, EAT);
	if (pthread_mutex_lock(&philo->last_meal_time_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	philo->last_meal_time = ft_get_time();
	if (pthread_mutex_unlock(&philo->last_meal_time_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	if (pthread_mutex_lock(&philo->eat_n_meal_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	(philo->eat_n_meal)++;
	if (pthread_mutex_unlock(&philo->eat_n_meal_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	ft_ms_sleep(philo->time_to_eat);
}

static void	ft_sleep(t_philo *philo)
{
	if (ft_stop_get(philo->table))
		return ;
	ft_put_action(ft_time(philo), philo, SLEEP);
	ft_ms_sleep(philo->time_to_sleep);
}

static void	ft_think(t_philo *philo)
{
	if (ft_stop_get(philo->table))
		return ;
	ft_put_action(ft_time(philo), philo, THINK);
}

//static void	ft_dead(t_philo *philo)
//{
//	if (philo->table->stop)
//		return ;
//	ft_put_action(ft_time(philo), philo->id, DIED);
//	philo->dead = 1;
//}

static void	*ft_routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_ms_sleep(50);
	while (ft_stop_get(philo->table) == 0)
	{
		ft_forks_up(philo);
		ft_eat(philo);
		ft_forks_down(philo);
		//if (philo->eat_n_meal == philo->max_meals)
		//	break;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

int	ft_start_simulation(t_data *table)
{
	pthread_t	*th_philo_id;
	pthread_t	th_monitor_id;

	int			i;
	if (ft_monitor_thread(table, &th_monitor_id))
		return (FAILED);
	i = 0;
	while (i < table->n_philosopher)
	{
		th_philo_id = &((table->philosophers)[i].thread_id);
		if (pthread_create(th_philo_id, NULL, &ft_routine, &(table->philosophers[i])))
		{
			ft_put_error(CREAT_THREAD_ERROR);
			table->stop = 1;
			return (FAILED);
		}
		i++;
	}
	if (ft_philos_join(table))
		return (FAILED);
	pthread_join(th_monitor_id, NULL);
	return (SUCCESS);
}
