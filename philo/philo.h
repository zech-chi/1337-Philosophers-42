/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:22 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/07 17:46:24 by zech-chi         ###   ########.fr       */
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
# define MUTEX_CREAT_ERROR -5
# define MUTEX_DESTROY_ERROR -6
# define MUTEX_LOCK_ERROR -7
# define MUTEX_UNLOCK_ERROR -8

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

/************************* philo struct *************************/
struct s_philo
{
	int				id_philo;
	int				id_left_fork;
	int				id_right_fork;
	pthread_t		id_thread;
	int				eat_n_meals;
	size_t			time_last_meal;
	pthread_mutex_t	mtx_time_last_meal;
	pthread_mutex_t	mtx_eat_n_meals;
	t_table			*table;
};

/************************* table struct *************************/
struct s_table
{
	int				n_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				start;
	int				stop;
	size_t			time_start;
	t_philo			*philos;
	pthread_mutex_t	*mtx_forks;
	pthread_mutex_t	mtx_n_philosophers;
	pthread_mutex_t	mtx_time_to_die;
	pthread_mutex_t	mtx_time_to_eat;
	pthread_mutex_t	mtx_time_to_sleep;
	pthread_mutex_t	mtx_max_meals;
	pthread_mutex_t	mtx_start;
	pthread_mutex_t	mtx_stop;
	pthread_mutex_t	mtx_time_start;
	pthread_mutex_t	mtx_put_action;
};

/************************* parsing.c *************************/
int		ft_parsing(t_table *table, int ac, char **av);

/************************* time.c *************************/
size_t	ft_time_cur_ms(void);
void	ft_time_sleep_ms(size_t t_ms);
size_t	ft_time_1(t_table *table);
size_t	ft_time_2(t_philo *philo);

/************************* tools.c *************************/
void	ft_put_on_stderr(char *msg);
void	ft_put_error(int error_id);
void	ft_put_action(size_t time, t_philo *philo, int action);

/************************* table.c *************************/
int		ft_table_init(t_table *table);
int		ft_table_mtx_init(t_table *table);
int		ft_table_mtx_destroy(t_table *table);
void	ft_table_destroy_them_all(t_table *table);

/************************* forks.c *************************/
int		ft_forks_create(t_table *table);
int		ft_forks_init(t_table *table);
int		ft_forks_destroy(t_table *table, int size);
void	ft_forks_up(t_philo *philo);
void	ft_forks_down(t_philo *philo);

/************************* philos.c *************************/
int		ft_philos_create(t_table *table);
void	ft_philos_init(t_table *table);
int		ft_philos_join(t_table *table);
int		ft_philos_mtx_init(t_table *table);
int		ft_philos_mtx_destroy(t_table *table);

/************************* mtx_get_{1}{2}.c *************************/
int		ft_mtx_get_n_philosophers(t_table *table);
int		ft_mtx_get_time_to_die(t_table *table);
int		ft_mtx_get_time_to_eat(t_table *table);
int		ft_mtx_get_time_to_sleep(t_table *table);
int		ft_mtx_get_max_meals(t_table *table);
int		ft_mtx_get_start(t_table *table);
int		ft_mtx_get_stop(t_table *table);
size_t	ft_mtx_get_time_start(t_table *table);
int		ft_mtx_get_eat_n_meals(t_philo *philo);
size_t	ft_mtx_get_time_last_meal(t_philo *philo);

/************************* mtx_set.c *************************/
void	ft_mtx_set_stop(t_table *table);
void	ft_mtx_set_start(t_table *table);
void	ft_mtx_set_time_last_meal(t_philo *philo);
void	ft_mtx_set_eat_n_meals(t_philo *philo);

/************************* mtx_tools.c *************************/
int		ft_mtx_lock(t_table *table, pthread_mutex_t *mtx_ptr);
int		ft_mtx_unlock(t_table *table, pthread_mutex_t *mtx_ptr);

/************************* routine.c *************************/
void	ft_dead(t_philo *philo);
void	*ft_routine(void *arg);

/************************* simulation.c *************************/
int		ft_simulation(t_table *table);

/************************* monitor.c *************************/
int		ft_monitor_thread_create(t_table *table, pthread_t *id_thread_monitor);
int		ft_monitor_thread_join(t_table *table, pthread_t id_thread_monitor);
void	*ft_monitor_job(void *arg);

//void	ft_print_data(t_table table);
#endif
