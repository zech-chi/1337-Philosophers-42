/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:01:23 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/19 00:11:28 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philos_create(t_table *table)
{
	table->philos_pid = malloc(sizeof(pid_t) * table->n_philosophers);
	if (!table->philos_pid)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_philo_init(t_table *table, t_philo *philo, int id_philo)
{
	int		error;

	error = 0;
	free(table->philos_pid);
	table->philos_pid = NULL;
	philo->id_philo = id_philo;
	philo->table = table;
	philo->time_last_meal = table->time_start;
	philo->eat_n_meals = 0;
	if (error)
		return (FAILED);
	return (SUCCESS);
}
