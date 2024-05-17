/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:39:36 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/17 20:55:41 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_time_cur_ms(void)
{
	struct timeval	tv;
	size_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time_ms);
}

void	ft_time_sleep_ms(size_t t_ms)
{
	size_t	t0;

	t0 = ft_time_cur_ms();
	while (ft_time_cur_ms() - t0 < t_ms)
		usleep(150);
}

size_t	ft_time_2(t_philo *philo)
{
	return (ft_time_cur_ms() - ft_sem_get_time_last_meal(philo));
}

size_t	ft_time_1(t_philo *philo, size_t cur_time)
{
	return (cur_time - ft_sem_get_time_start(philo));
}
