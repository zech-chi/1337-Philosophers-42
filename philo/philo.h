/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:10:22 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 16:14:35 by zech-chi         ###   ########.fr       */
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
};

/************************* parsing.c *************************/
int	ft_parsing(t_table *table, int ac, char **av);

/************************* tools.c *************************/
void	ft_put_on_stderr(char *msg);
void	ft_put_error(int error_id);

/************************* table.c *************************/
/************************* forks.c *************************/
int		ft_forks_create(t_table *table);
int		ft_forks_init(t_table *table);
int		t_forks_destroy(t_table *table, int size);
void	ft_forks_up(t_philo *philo);
void	ft_forks_down(t_philo *philo);

/************************* philos.c *************************/
int		ft_philos_create(t_table *table);
int		ft_philos_join(t_table *table);
void	ft_philos_init(t_table *table);
#endif
