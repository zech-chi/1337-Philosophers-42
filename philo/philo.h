/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:32:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/21 21:03:01 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>

typedef struct	s_data
{
	int	n_philosopher;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_num_of_meals;
}	t_data;

#endif
