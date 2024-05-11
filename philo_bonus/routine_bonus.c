/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:44:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 19:37:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_eat(t_philo *philo)
{
	if (ft_put_action(ft_time_1(philo->table), philo, EAT))
		return (FAILED);
	ft_sem_set_time_last_meal(philo);
	(philo->eat_n_meals)++;
	ft_time_sleep_ms(philo->table->time_to_eat);
	return (SUCCESS);
}

static int	ft_sleep(t_philo *philo)
{
	if (ft_put_action(ft_time_1(philo->table), philo, SLEEP))
		return (FAILED);
	ft_time_sleep_ms(philo->table->time_to_sleep);
	return (SUCCESS);
}

static int	ft_think(t_philo *philo)
{
	if (ft_put_action(ft_time_1(philo->table), philo, THINK))
		return (FAILED);
	return (SUCCESS);
}

int	ft_dead(t_philo *philo)
{
	if (ft_put_action(ft_time_1(philo->table), philo, DIED))
		return (FAILED);
	return (SUCCESS);
}

void	ft_philo(t_table *table, int id_philo, size_t time_start)
{
	t_philo	philo;

	philo.id_philo = id_philo;
	philo.table = table;
	philo.time_last_meal = time_start;
	ft_observer(&philo);
	if (id_philo % 2)
		ft_time_sleep_ms(table->time_to_eat);
	while (1)
	{
		if (ft_forks_up(&philo) == FAILED)
			exit(FAILED);
		if (ft_eat(&philo))
			exit(FAILED);
		if (ft_forks_down(&philo) == FAILED)
			exit(FAILED);
		if (philo.eat_n_meals == table->max_meals)
			exit(SUCCESS);
		if (ft_sleep(&philo))
			exit(FAILED);
		if (ft_think(&philo))
			exit(FAILED);
	}
}
