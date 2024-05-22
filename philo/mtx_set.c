/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 14:39:28 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:10:36 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mtx_set_stop(t_table *table)
{
	if (pthread_mutex_lock(&table->mtx_stop))
		return ;
	table->stop = 1;
	if (pthread_mutex_unlock(&table->mtx_stop))
		return ;
}

void	ft_mtx_set_time_start(t_table *table)
{
	ft_mtx_lock(table, &table->mtx_time_start);
	table->time_start = ft_time_cur_ms();
	ft_mtx_unlock(table, &table->mtx_time_start);
}

void	ft_mtx_set_start(t_table *table)
{
	ft_mtx_lock(table, &table->mtx_start);
	table->start = 1;
	ft_mtx_unlock(table, &table->mtx_start);
}

void	ft_mtx_set_time_last_meal(t_philo *philo)
{
	ft_mtx_lock(philo->table, &philo->mtx_time_last_meal);
	philo->time_last_meal = ft_time_cur_ms();
	ft_mtx_unlock(philo->table, &philo->mtx_time_last_meal);
}

void	ft_mtx_set_eat_n_meals(t_philo *philo)
{
	ft_mtx_lock(philo->table, &philo->mtx_eat_n_meals);
	(philo->eat_n_meals)++;
	ft_mtx_unlock(philo->table, &philo->mtx_eat_n_meals);
}
