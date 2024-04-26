/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:35:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:40 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philos_create(t_data *table)
{
	table->philosophers = malloc(sizeof(t_philo) * table->n_philosopher);
	if (!table->philosophers)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_philos_join(t_data *table)
{
	int			i;
	pthread_t	th_id;

	i = 0;
	while (i < table->n_philosopher)
	{
		th_id = ((table->philosophers)[i].thread_id);
		if (pthread_join(th_id, NULL))
		{
			ft_put_error(JOIN_THREAD_ERROR);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

void	ft_philos_init(t_data *table)
{
	int	i;
	int	n;

	if (!table->philosophers)
		return ;
	n = table->n_philosopher;
	i = 0;
	while (i < n)
	{
		(table->philosophers)[i].id = i;
		(table->philosophers)[i].right_fork_id = i;
		(table->philosophers)[i].left_fork_id = (i + 1) % n;
		(table->philosophers)[i].eat_n_meal = 0;
		(table->philosophers)[i].table = table;
		i++;
	}
}
