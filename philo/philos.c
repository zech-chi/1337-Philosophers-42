/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:09:19 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 16:15:35 by zech-chi         ###   ########.fr       */
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

int	ft_philos_join(t_table *table)
{
	int			i;
	pthread_t	th_id;

	i = 0;
	while (i < table->n_philosophers)
	{
		th_id = ((table->philos)[i].id_thread);
		if (pthread_join(th_id, NULL))
		{
			ft_put_error(JOIN_THREAD_ERROR);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_philos_mtx_init(t_philo *philo)
{
			pthread_mutex_init(&(table->philos)[i].mtx_time_last_meal, NULL);
		pthread_mutex_init(&(table->philos)[i].mtx_eat_n_meals, NULL);
}

void	ft_philos_init(t_table *table)
{
	int	i;
	int	n;
	size_t		start_time;

	if (!table->philos)
		return ;
	n = table->n_philosophers;
	start_time = ft_get_time();
	i = 0;
	while (i < n)
	{
		(table->philos)[i].id_philo = i;
		(table->philos)[i].id_right_fork = i;
		(table->philos)[i].id_left_fork = (i + 1) % n;
		(table->philos)[i].eat_n_meals = 0;
		(table->philos)[i].table = table;
		(table->philos)[i].time_last_meal = start_time;

		i++;
	}
}
