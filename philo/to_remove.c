/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:39:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/22 18:50:34 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_data(t_data data)
{
	printf("n_philosopher : %d\n", data.n_philosopher);
	printf("time_to_die   : %d\n", data.time_to_die);
	printf("time_to_eat   : %d\n", data.time_to_eat);
	printf("time_to_sleep : %d\n", data.time_to_sleep);
	printf("max_meals     : %d\n", data.max_meals);
}
