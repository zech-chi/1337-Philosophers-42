/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:32:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/22 18:44:42 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
	int	n_philosopher;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
}	t_data;

/************************* parsing.c *************************/
int	ft_parse_data(t_data *data, int ac, char **av);

/************************* philo.c *************************/
void	ft_puterror(void);

/************************* to_remove.c *************************/
void	ft_print_data(t_data data);

#endif
