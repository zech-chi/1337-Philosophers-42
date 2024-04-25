/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:39:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 11:34:24 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_data table)
{
	printf("n_philosopher : %d\n", table.n_philosopher);
	printf("time_to_die   : %d\n", table.time_to_die);
	printf("time_to_eat   : %d\n", table.time_to_eat);
	printf("time_to_sleep : %d\n", table.time_to_sleep);
	printf("max_meals     : %d\n", table.max_meals);
	if (!table.philosophers)
		return ;
	for (int i = 0; i < table.n_philosopher; i++)
	{
		printf("philo_id: %d, ", (table.philosophers)[i].id);
		printf("left_fork_id <- %d, ", (table.philosophers)[i].left_fork_id);
		printf("right_fork_id -> %d, ", (table.philosophers)[i].right_fork_id);
		printf("eat_n_meal: %d\n", (table.philosophers)[i].eat_n_meal);
	}
}
