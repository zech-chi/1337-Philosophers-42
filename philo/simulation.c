/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/26 14:38:53 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_ms_sleep(size_t t_ms)
{
	size_t	cur_time;

	cur_time = ft_get_time();
	while (ft_get_time() - cur_time < t_ms)
	{
		usleep(10);
	}
}

void	ft_eat(t_philo *philo)
{
	ft_put_action(ft_time(philo), philo->id, EAT);
	ft_ms_sleep(philo->table->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	ft_put_action(ft_time(philo), philo->id, SLEEP);
	ft_ms_sleep(philo->table->time_to_sleep);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_action_time = ft_get_time();
	if (philo->id % 2)
		ft_ms_sleep(50);
	while (1)
	{
		ft_forks_up(philo);
		ft_eat(philo);
		ft_forks_down(philo);
		ft_sleep(philo);
		ft_put_action(ft_time(philo), philo->id, THINK);
	}
	return (NULL);
}

int	ft_start_simulation(t_data *table)
{
	pthread_t	*th_id;
	int			i;

	table->start_time = ft_get_time();
	i = 0;
	while (i < table->n_philosopher)
	{
		th_id = &((table->philosophers)[i].thread_id);
		if (pthread_create(th_id, NULL, &ft_routine, &(table->philosophers[i])))
		{
			ft_put_error(CREAT_THREAD_ERROR);
			table->error = 1;
			return (FAILED);
		}
		i++;
	}
	if (ft_philos_join(table))
		return (FAILED);
	return (SUCCESS);
}
