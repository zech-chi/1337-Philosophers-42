/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:55:57 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:40:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_table_sem_init(t_table *table)
{
	int	error;

	error = 0;
	sem_unlink(SEM_FORKS_FILE);
	sem_unlink(SEM_PUT_ACTION_FILE);
	sem_unlink(SEM_TIME_START_FILE);
	sem_unlink(SEM_EAT_N_MEALS_FILE);
	sem_unlink(SEM_TIME_LAST_MEAL_FILE);
	table->sem_forks = ft_sem_open(SEM_FORKS_FILE, \
	table->n_philosophers, &error);
	table->sem_put_action = ft_sem_open(SEM_PUT_ACTION_FILE, 1, &error);
	table->sem_time_start = ft_sem_open(SEM_TIME_START_FILE, 1, &error);
	table->sem_eat_n_meals = ft_sem_open(SEM_EAT_N_MEALS_FILE, 1, &error);
	table->sem_time_last_meal = ft_sem_open(SEM_TIME_LAST_MEAL_FILE, 1, &error);
	if (error)
		return (FAILED);
	return (SUCCESS);
}

int	ft_table_init(t_table *table)
{
	table->philos_pid = NULL;
	if (ft_philos_create(table) == FAILED)
		return (FAILED);
	if (ft_table_sem_init(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	return (SUCCESS);
}

void	ft_table_destroy_them_all(t_table *table)
{
	sem_close(table->sem_forks);
	sem_close(table->sem_eat_n_meals);
	sem_close(table->sem_put_action);
	sem_close(table->sem_time_last_meal);
	sem_close(table->sem_time_start);
	sem_unlink(SEM_FORKS_FILE);
	sem_unlink(SEM_PUT_ACTION_FILE);
	sem_unlink(SEM_TIME_START_FILE);
	sem_unlink(SEM_EAT_N_MEALS_FILE);
	sem_unlink(SEM_TIME_LAST_MEAL_FILE);
	ft_kill_them_all(table);
	free(table->philos_pid);
	table->philos_pid = NULL;
}

void	ft_kill_them_all(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philosophers)
	{
		kill(table->philos_pid[i], SIGINT);
		i++;
	}
}
