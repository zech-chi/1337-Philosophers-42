/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:29:30 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 23:04:27 by zech-chi         ###   ########.fr       */
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

size_t	ft_time(t_philo *philo)
{
	size_t	cur_time;
	size_t	diff;

	cur_time = ft_get_time();
	diff = cur_time - philo->table->start_time;
	return (diff);
}

void	ft_eat(t_philo *philo)
{

	pthread_mutex_lock(&(philo->table->forks)[philo->left_fork_id]);
	ft_put_action(ft_time(philo), philo->id, TAKE_FORK);
	pthread_mutex_lock(&(philo->table->forks)[philo->right_fork_id]);
	ft_put_action(ft_time(philo), philo->id, TAKE_FORK);
	ft_put_action(ft_time(philo), philo->id, EAT);
	ft_ms_sleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&(philo->table->forks)[philo->left_fork_id]);
	pthread_mutex_unlock(&(philo->table->forks)[philo->right_fork_id]);
}
//void	ft_eat(t_philo *philo)
//{
//	size_t	cur_time;
//	size_t	diff;

//	cur_time = ft_get_time();
//	diff = cur_time - philo->table->start_time;
//	pthread_mutex_lock(philo->left_fork_id);
//	ft_put_action(diff, philo->id, EAT);
//	ft_ms_sleep(philo->table->time_to_eat);
//}

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
	while (1)
	{
		ft_eat(philo);
		//ft_think();
		ft_sleep(philo);
	}
	return (NULL);
}

//void	*ft_routine(void *arg)
//{
//	t_philo	*philo;

//	philo = (t_philo *)arg;
//	printf("%d\n", philo->id);
//	return (NULL);
//}

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
