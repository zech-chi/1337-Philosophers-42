/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:32:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/23 14:00:49 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	int	n_philosopher;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	int	dead;
}	t_data;

/*
	action {
		0: eat
		1: think
		3: sleep
	}
*/
typedef struct s_philo
{
	int	id;
	int	left_fork;
	int	left_fork_id;
	int	right_fork;
	int	right_fork_id;
	int	action;
	int	last_action_time;
	int	eat_n_meal;
}	t_philo;

/************************* parsing.c *************************/
int	ft_parse_data(t_data *data, int ac, char **av);

/************************* philo.c *************************/
void	ft_puterror(void);

/************************* to_remove.c *************************/
void	ft_print_data(t_data data);

/************************* simulation.c *************************/
/*
void	ft_eat();
void	ft_think();
void	ft_take_fork();
void	ft_put_fork();
*/

#endif
