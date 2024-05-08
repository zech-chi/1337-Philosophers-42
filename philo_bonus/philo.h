/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:10:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/08 15:26:34 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

//exit status
# define SUCCESS 0
# define FAILED 1

//philo action
# define TAKE_FORK 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DIED 6

//error_id
# define PARSING_ERROR -1
# define MALLOC_ERROR -2
# define CREAT_THREAD_ERROR -3
# define JOIN_THREAD_ERROR -4

typedef struct s_table	t_table;

/************************* table struct *************************/
struct s_table
{
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	size_t			time_start;
};

/************************* parsing.c *************************/
int		ft_parsing(t_table *table, int ac, char **av);

/************************* tools.c *************************/
void	ft_put_on_stderr(char *msg);
void	ft_put_error(int error_id);

#endif