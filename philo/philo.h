/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:32:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 18:19:30 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//exit status
# define SUCCESS 0
# define FAILED 1

//error_id
# define PARSING_ERROR 0
# define MALLOC_ERROR 1
# define CREAT_THREAD_ERROR 2
# define JOIN_THREAD_ERROR 3
# define MUTEX_CREAT_ERROR 4
# define MUTEX_DESTROY_ERROR 4

//direction
# define RIGHT 1
# define LEFT -1

//philo action
# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_philo
{
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	int			action;
	size_t		last_action_time;
	int			eat_n_meal;
	pthread_t	thread_id;
	t_data		*table;
};

typedef struct s_data
{
	int				n_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				dead;
	size_t			start_time;
	size_t			cur_time;
	int				error;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
}	t_data;

/************************* parsing.c *************************/
int			ft_parse_data(t_data *table, int ac, char **av);

/************************* tools.c *************************/
void		ft_put_error(int error_id);
void		ft_free_them_all(t_data *table);
void		ft_put_action(time_t time, int philo_id, int action);
size_t		ft_get_time(void);

/************************* forks.c *************************/
int			ft_forks_create(t_data *table);
int			ft_forks_init(t_data *table);
int			ft_forks_destroy(t_data *table, int size);

/************************* philos.c *************************/
int			ft_philos_create(t_data *table);
void		ft_philos_init(t_data *table);
int			ft_philos_join(t_data *table);

/************************* simulation.c *************************/
int			ft_start_simulation(t_data *table);
void		*ft_routine(void	*table);
/*
void	ft_eat();
void	ft_think();
void	ft_take_fork();
void	ft_put_fork();
*/

/************************* to_remove.c *************************/
void		ft_print_data(t_data table);

#endif
