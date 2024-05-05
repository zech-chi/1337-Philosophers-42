/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_get_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:40:14 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/05 18:47:39 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_get_n_philosophers(t_table *table)
{
	int	n_philosophers;

	ft_mtx_lock(table, &table->mtx_n_philosophers);
	n_philosophers = table->n_philosophers;
	ft_mtx_unlock(table, &table->mtx_n_philosophers);
	return (n_philosophers);
}

int	ft_mtx_get_time_to_die(t_table *table)
{
	int	time_to_die;

	ft_mtx_lock(table, &table->mtx_time_to_die);
	time_to_die = table->time_to_die;
	ft_mtx_unlock(table, &table->mtx_time_to_die);
	return (time_to_die);
}

int	ft_mtx_get_time_to_eat(t_table *table)
{
	int	time_to_eat;

	ft_mtx_lock(table, &table->mtx_time_to_eat);
	time_to_eat = table->time_to_eat;
	ft_mtx_unlock(table, &table->mtx_time_to_eat);
	return (time_to_eat);
}

int	ft_mtx_get_time_to_sleep(t_table *table)
{
	int	time_to_sleep;

	ft_mtx_lock(table, &table->mtx_time_to_sleep);
	time_to_sleep = table->time_to_sleep;
	ft_mtx_unlock(table, &table->mtx_time_to_sleep);
	return (time_to_sleep);
}

int	ft_mtx_get_max_meals(t_table *table)
{
	int	max_meals;

	ft_mtx_lock(table, &table->mtx_max_meals);
	max_meals = table->max_meals;
	ft_mtx_unlock(table, &table->mtx_max_meals);
	return (max_meals);
}
