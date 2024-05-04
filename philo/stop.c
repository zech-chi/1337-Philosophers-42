/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:12:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 10:41:41 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_stop_set(t_data *table)
{
	if (pthread_mutex_lock(&table->stop_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(table);
	}
	table->stop = 1;
	if (pthread_mutex_unlock(&table->stop_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(table);
	}
}

int	ft_stop_get(t_data *table)
{
	int	stop;

	if (pthread_mutex_lock(&table->stop_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(table);
	}
	stop =  table->stop;
	if (pthread_mutex_unlock(&table->stop_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(table);
	}
	return (stop);
}

int	ft_get_eat_n_meal(t_philo *philo)
{
	int	eat_n_meal;

	if (pthread_mutex_lock(&philo->eat_n_meal_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	eat_n_meal =  philo->eat_n_meal;
	if (pthread_mutex_unlock(&philo->eat_n_meal_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	return (eat_n_meal);
}

int	ft_get_max_meals(t_philo *philo)
{
	int	max_meals;

	if (pthread_mutex_lock(&philo->max_meals_mtx))
	{
		ft_put_error(MUTEX_LOCK_ERROR);
		ft_stop_set(philo->table);
	}
	max_meals =  philo->max_meals;
	if (pthread_mutex_unlock(&philo->max_meals_mtx))
	{
		ft_put_error(MUTEX_UNLOCK_ERROR);
		ft_stop_set(philo->table);
	}
	return (max_meals);
}
