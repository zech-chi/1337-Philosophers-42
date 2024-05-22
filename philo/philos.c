/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:09:19 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 10:31:56 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philos_create(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->n_philosophers);
	if (!table->philos)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_philos_detach(t_table *table)
{
	int			i;
	pthread_t	th_id;
	int			n_philosophers;

	n_philosophers = ft_mtx_get_n_philosophers(table);
	i = 0;
	while (i < n_philosophers)
	{
		th_id = ((table->philos)[i].id_thread);
		if (pthread_detach(th_id))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

int	ft_philos_mtx_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < ft_mtx_get_n_philosophers(table))
	{
		if (pthread_mutex_init(&((table->philos)[i]).mtx_time_last_meal, NULL))
			return (FAILED);
		if (pthread_mutex_init(&((table->philos)[i]).mtx_eat_n_meals, NULL))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

int	ft_philos_mtx_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < ft_mtx_get_n_philosophers(table))
	{
		if (pthread_mutex_destroy(&(table->philos)[i].mtx_time_last_meal))
			return (FAILED);
		if (pthread_mutex_destroy(&(table->philos)[i].mtx_eat_n_meals))
			return (FAILED);
		i++;
	}
	return (SUCCESS);
}

void	ft_philos_init(t_table *table)
{
	int		i;
	size_t	start_time;
	int		n_philosophers;

	if (!table->philos)
		return ;
	n_philosophers = ft_mtx_get_n_philosophers(table);
	start_time = table->time_start;
	i = 0;
	while (i < n_philosophers)
	{
		(table->philos)[i].id_philo = i;
		(table->philos)[i].id_right_fork = i;
		(table->philos)[i].id_left_fork = (i + 1) % n_philosophers;
		(table->philos)[i].eat_n_meals = 0;
		(table->philos)[i].table = table;
		(table->philos)[i].time_last_meal = start_time;
		i++;
	}
}
