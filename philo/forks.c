/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:16:51 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 12:38:42 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_create(t_data *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philosopher);
	if (!table->forks)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_forks_init(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosopher)
	{
		if (pthread_mutex_init(table->forks + i, NULL))
		{
			ft_put_error(MUTEX_CREAT_ERROR);
			ft_forks_destroy(table, i);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_forks_destroy(t_data *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(table->forks + i))
		{
			ft_put_error(MUTEX_DESTROY_ERROR);
			return (FAILED);
		}
		i++;
	}
	return (SUCCESS);
}
