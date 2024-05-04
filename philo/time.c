/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:51:51 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 10:45:22 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	struct timeval	tv;
	size_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}

size_t	ft_time(t_philo *philo)
{
	size_t	diff;

	if (pthread_mutex_lock(&philo->start_time_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	diff = ft_get_time() - philo->start_time;
	if (pthread_mutex_unlock(&philo->start_time_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	return (diff);
}

void	ft_ms_sleep(size_t t_ms)
{
	size_t	cur_time;

	cur_time = ft_get_time();
	while (ft_get_time() - cur_time < t_ms)
	{
		usleep(10);
	}
}

size_t	ft_diff_time(t_philo *philo)
{
	size_t	diff;

	if (pthread_mutex_lock(&philo->last_meal_time_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	diff = ft_get_time() - philo->last_meal_time;
	if (pthread_mutex_unlock(&philo->last_meal_time_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	return (diff);
}
