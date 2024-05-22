/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_get_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:47:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 10:40:44 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_get_stop(t_table *table)
{
	int	stop;

	ft_mtx_lock(table, &table->mtx_stop);
	stop = table->stop;
	ft_mtx_unlock(table, &table->mtx_stop);
	return (stop);
}

size_t	ft_mtx_get_time_start(t_table *table)
{
	size_t	time_start;

	ft_mtx_lock(table, &table->mtx_time_start);
	time_start = table->time_start;
	ft_mtx_unlock(table, &table->mtx_time_start);
	return (time_start);
}

int	ft_mtx_get_eat_n_meals(t_philo *philo)
{
	int	eat_n_meals;

	ft_mtx_lock(philo->table, &philo->mtx_eat_n_meals);
	eat_n_meals = philo->eat_n_meals;
	ft_mtx_unlock(philo->table, &philo->mtx_eat_n_meals);
	return (eat_n_meals);
}

size_t	ft_mtx_get_time_last_meal(t_philo *philo)
{
	size_t	time_last_meal;

	ft_mtx_lock(philo->table, &philo->mtx_time_last_meal);
	time_last_meal = philo->time_last_meal;
	ft_mtx_unlock(philo->table, &philo->mtx_time_last_meal);
	return (time_last_meal);
}
