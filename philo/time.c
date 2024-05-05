/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:59:07 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/05 18:36:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		usleep(25);
}

size_t	ft_time_1(t_table *table)
{
	return (ft_time_cur_ms() - ft_mtx_get_time_start(table));
}

size_t	ft_time_2(t_philo *philo)
{
	return (ft_time_cur_ms() - ft_mtx_get_time_last_meal(philo));
}
