/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:39:36 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 15:57:59 by zech-chi         ###   ########.fr       */
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
		usleep(250);
}

size_t	ft_time_1(t_table *table)
{
	//return (ft_time_cur_ms() - table->time_start); // to lock
	return (ft_time_cur_ms() - ft_sem_get_time_start(table));
}

size_t	ft_time_2(t_philo *philo)
{
	//return (ft_time_cur_ms() - philo->time_last_meal); // to lock
	return (ft_time_cur_ms() - ft_sem_get_time_last_meal(philo)); // to lock
}
