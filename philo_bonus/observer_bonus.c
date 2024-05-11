/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:01:43 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 19:35:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*ft_observer_job(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_time_2(philo) > (size_t)philo->table->time_to_die)
			return (ft_dead(philo), kill(getpid(), SIGINT), NULL);
		usleep(5000);
	}
	return (NULL);
}

int	ft_observer(t_philo *philo)
{
	pthread_t	id_thread_observer;

	if (pthread_create(&id_thread_observer, NULL, &ft_observer_job, philo))
	{
		ft_put_error(THREAD_CREATE_ERROR);
		return (FAILED);
	}
	if (pthread_detach(id_thread_observer))
	{
		ft_put_error(THREAD_DETACH_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}
