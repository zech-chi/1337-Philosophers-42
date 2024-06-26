/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:44:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:56:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_eat(t_philo *philo)
{
	size_t	cur_time;

	cur_time = ft_time_cur_ms();
	if (ft_put_action(ft_time_1(philo, cur_time), philo, EAT))
		return (FAILED);
	(philo->eat_n_meals)++;
	if (philo->eat_n_meals != philo->table->max_meals)
		ft_sem_set_time_last_meal(philo, cur_time);
	ft_time_sleep_ms(philo->table->time_to_eat);
	return (SUCCESS);
}

static int	ft_sleep(t_philo *philo)
{
	size_t	cur_time;

	cur_time = ft_time_cur_ms();
	if (ft_put_action(ft_time_1(philo, cur_time), philo, SLEEP))
		return (FAILED);
	ft_time_sleep_ms(philo->table->time_to_sleep);
	return (SUCCESS);
}

static int	ft_think(t_philo *philo)
{
	size_t	cur_time;

	cur_time = ft_time_cur_ms();
	if (ft_put_action(ft_time_1(philo, cur_time), philo, THINK))
		return (FAILED);
	return (SUCCESS);
}

int	ft_dead(t_philo *philo)
{
	size_t	cur_time;

	cur_time = ft_time_cur_ms();
	if (ft_put_action(ft_time_1(philo, cur_time), philo, DIED))
		return (FAILED);
	return (SUCCESS);
}

void	ft_philo(t_table *table, int id_philo)
{
	t_philo	philo;

	if (ft_philo_init(table, &philo, id_philo))
		exit(FAILED);
	if (table->max_meals == 0)
		exit(SUCCESS);
	ft_observer(&philo);
	if (id_philo % 2)
		ft_time_sleep_ms(table->time_to_eat - 10);
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
	exit(SUCCESS);
}
