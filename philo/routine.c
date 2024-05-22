/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:56:35 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 10:47:28 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	size_t	cur_time;

	if (ft_mtx_get_stop(philo->table))
		return ;
	cur_time = ft_time_cur_ms();
	ft_put_action(ft_time_1(philo->table, cur_time), philo, EAT);
	ft_mtx_set_time_last_meal(philo, cur_time);
	ft_mtx_set_eat_n_meals(philo);
	ft_time_sleep_ms(ft_mtx_get_time_to_eat(philo->table));
}

static void	ft_sleep(t_philo *philo)
{
	size_t	cur_time;

	if (ft_mtx_get_stop(philo->table))
		return ;
	cur_time = ft_time_cur_ms();
	ft_put_action(ft_time_1(philo->table, cur_time), philo, SLEEP);
	ft_time_sleep_ms(ft_mtx_get_time_to_sleep(philo->table));
}

static void	ft_think(t_philo *philo)
{
	size_t	cur_time;

	if (ft_mtx_get_stop(philo->table))
		return ;
	cur_time = ft_time_cur_ms();
	ft_put_action(ft_time_1(philo->table, cur_time), philo, THINK);
}

void	ft_dead(t_philo *philo)
{
	size_t	cur_time;

	if (ft_mtx_get_stop(philo->table))
		return ;
	cur_time = ft_time_cur_ms();
	ft_mtx_set_stop(philo->table);
	ft_put_action(ft_time_1(philo->table, cur_time), philo, DIED);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2)
		ft_time_sleep_ms(ft_mtx_get_time_to_eat(philo->table) - 10);
	while (ft_mtx_get_stop(philo->table) == 0)
	{
		ft_forks_up(philo);
		ft_eat(philo);
		ft_forks_down(philo);
		if (ft_mtx_get_eat_n_meals(philo) == ft_mtx_get_max_meals(philo->table))
			break ;
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
