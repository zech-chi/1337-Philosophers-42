/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:44:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/08 23:46:58 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_table *table)
{
	//if (ft_mtx_get_stop(philo->table))
	//	return ;
	ft_put_action(ft_time_1(philo->table), philo, EAT);
	ft_mtx_set_time_last_meal(philo);
	ft_mtx_set_eat_n_meals(philo);
	ft_time_sleep_ms(ft_mtx_get_time_to_eat(philo->table));
}

static void	ft_sleep(t_table *table)
{
	//if (ft_mtx_get_stop(philo->table))
	//	return ;
	ft_put_action(ft_time_1(philo->table), philo, SLEEP);
	ft_time_sleep_ms(ft_mtx_get_time_to_sleep(philo->table));
}

static void	ft_think(t_table *table)
{
	//if (ft_mtx_get_stop(philo->table))
	//	return ;
	ft_put_action(ft_time_1(philo->table), philo, THINK);
}

void	ft_dead(t_table *table)
{
	//if (ft_mtx_get_stop(philo->table))
	//	return ;
	ft_mtx_set_stop(philo->table);
	ft_put_action(ft_time_1(philo->table), philo, DIED);
}

int	ft_philo(t_table *table)
{
	while (1)
	{
		ft
	}
}
