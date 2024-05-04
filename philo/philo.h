/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:32:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/02 19:17:09 by zech-chi         ###   ########.fr       */
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
# define MUTEX_DESTROY_ERROR 5
# define MUTEX_LOCK_ERROR 6
# define MUTEX_UNLOCK_ERROR 7

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
	pthread_t		thread_id;
	size_t			start_time;
	size_t			last_meal_time;
	int				id;
	int				left_fork_id;
	int				right_fork_id;
	int				eat_n_meal;
	int				n_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	pthread_mutex_t	last_meal_time_mtx;
	pthread_mutex_t	start_time_mtx;
	pthread_mutex_t	eat_n_meal_mtx;
	pthread_mutex_t	max_meals_mtx;
	t_data		*table;
};

typedef struct s_data
{
	int				n_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	size_t			start_time;
	int				stop;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	put_action_mtx;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t	time_mtx;
	pthread_mutex_t	diff_time_mtx;
	pthread_mutex_t	t6;
}	t_data;

/************************* parsing.c *************************/
int			ft_parse_data(t_data *table, int ac, char **av);

/************************* tools.c *************************/
void		ft_put_error(int error_id);
void		ft_free_them_all(t_data *table);
void		ft_put_action(time_t time, t_philo *philo, int action);
size_t		ft_get_time(void);
size_t		ft_time(t_philo *philo);

/************************* time.c *************************/
size_t		ft_get_time(void);
size_t		ft_time(t_philo *philo);
void		ft_ms_sleep(size_t t_ms);
size_t		ft_diff_time(t_philo *philo);

/************************* forks.c *************************/
int			ft_forks_create(t_data *table);
int			ft_forks_init(t_data *table);
int			ft_forks_destroy(t_data *table, int size);
void		ft_forks_up(t_philo *philo);
void		ft_forks_down(t_philo *philo);

/************************* philos.c *************************/
int			ft_philos_create(t_data *table);
void		ft_philos_init(t_data *table);
int			ft_philos_join(t_data *table);

/************************* monitor.c *************************/
int			ft_monitor_thread(t_data *table, pthread_t *th_monitor);

/************************* simulation.c *************************/
int			ft_start_simulation(t_data *table);

/************************* to_remove.c *************************/
void		ft_print_data(t_data table);

/************************* stop.c *************************/
void		ft_stop_set(t_data *table);
int			ft_stop_get(t_data *table);
int			ft_get_eat_n_meal(t_philo *philo);
int			ft_get_max_meals(t_philo *philo);

#endif
