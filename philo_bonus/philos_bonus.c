/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:01:23 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/18 23:16:27 by zech-chi         ###   ########.fr       */
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
	sem_unlink(SEM_TIME_START_FILE);
	sem_unlink(SEM_EAT_N_MEALS_FILE);
	sem_unlink(SEM_TIME_LAST_MEAL_FILE);
	philo->sem_time_start = ft_sem_open(SEM_TIME_START_FILE, 1, &error);
	philo->sem_eat_n_meals = ft_sem_open(SEM_EAT_N_MEALS_FILE, 1, &error);
	philo->sem_time_last_meal = ft_sem_open(SEM_TIME_LAST_MEAL_FILE, 1, &error);
	philo->id_philo = id_philo;
	philo->table = table;
	philo->time_last_meal = table->time_start;
	philo->eat_n_meals = 0;
	if (error)
		return (FAILED);
	return (SUCCESS);
}

int	ft_philo_destroy(t_philo *philo)
{
	int	err;

	err = 0;
	err -= sem_close(philo->sem_time_start);
	err -= sem_close(philo->sem_eat_n_meals);
	err -= sem_close(philo->sem_time_last_meal);
	err -= sem_unlink(SEM_TIME_START_FILE);
	err -= sem_unlink(SEM_EAT_N_MEALS_FILE);
	err -= sem_unlink(SEM_TIME_LAST_MEAL_FILE);
	if (err)
		return (FAILED);
	return (SUCCESS);
}
