/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:10:16 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 19:48:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

//exit status
# define SUCCESS 0
# define FAILED 1

//philo action
# define TAKE_FORK 2
# define EAT 3
# define SLEEP 4
# define THINK 5
# define DIED 6

//sem_files
# define SEM_FORKS_FILE "forks_sem"
# define SEM_PUT_ACTION_FILE "put_action_sem"
# define SEM_TIME_START_FILE "time_start_sem"
# define SEM_EAT_N_MEALS_FILE "eat_n_meals_sem"
# define SEM_TIME_LAST_MEAL_FILE "time_last_meal_sem"

//error_id
# define PARSING_ERROR -1
# define MALLOC_ERROR -2
# define THREAD_CREATE_ERROR -3
# define THREAD_DETACH_ERROR -4
# define SEM_OPEN_ERROR -5
# define SEM_CLOSE_ERROR -6
# define SEM_POST_ERRPR -7
# define SEM_WAIT_ERROR -8
# define SEM_UNLINK_ERROR -9
# define FORK_ERROR -10

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

/************************* philo struct *************************/
struct s_philo
{
	int		id_philo;
	int		eat_n_meals;
	size_t	time_last_meal;
	t_table	*table;
};

/************************* table struct *************************/
struct s_table
{
	int		n_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		max_meals;
	size_t	time_start;
	pid_t	*philos_pid;
	sem_t	*sem_forks;
	sem_t	*sem_put_action;
	sem_t	*sem_time_start;
	sem_t	*sem_eat_n_meals;
	sem_t	*sem_time_last_meal;
};

/************************* parsing_bonus.c *************************/
int		ft_parsing(t_table *table, int ac, char **av);

/************************* tools_bonus.c *************************/
void	ft_put_on_stderr(char *msg);
void	ft_put_error(int error_id);
int		ft_put_action(size_t time, t_philo *philo, int action);

/************************* time_bonus.c *************************/
size_t	ft_time_cur_ms(void);
void	ft_time_sleep_ms(size_t t_ms);
size_t	ft_time_1(t_table *table);
size_t	ft_time_2(t_philo *philo);

/************************* table_bonus.c *************************/
int		ft_table_init(t_table *table);
int		ft_table_destroy_them_all(t_table *table);
void	ft_kill_them_all(t_table *table);

/************************* forks_bonus.c *************************/
int		ft_forks_up(t_philo *philo);
int		ft_forks_down(t_philo *philo);

/************************* philos_bonus.c *************************/
int		ft_philos_create(t_table *table);

/************************* simulation.c *************************/
int		ft_simulation(t_table *table);

/************************* routine_bonus.c *************************/
int		ft_dead(t_philo *philo);
void	ft_philo(t_table *table, int id_philo, size_t time_start);

/************************* sem_tools_bonus.c *************************/
sem_t	*ft_sem_open(char *file_name, int counter, int *error);
//int		ft_sem_get_eat_n_meals(t_philo *philo);
size_t	ft_sem_get_time_start(t_table *table);
size_t	ft_sem_get_time_last_meal(t_philo *philo);
void	ft_sem_set_time_last_meal(t_philo *philo);

/************************* observer_bonus.c *************************/
int		ft_observer(t_philo *philo);

#endif