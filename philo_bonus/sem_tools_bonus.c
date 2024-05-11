/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:59:11 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 15:10:57 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(char *file_name, int counter, int *error)
{
	sem_t	*s;

	s = sem_open(file_name, O_CREAT, 0644, counter);
	if (s == SEM_FAILED)
	{
		ft_put_error(SEM_OPEN_ERROR);
		*error = 1;
	}
	return (s);
}

//int	ft_sem_get_eat_n_meals(t_philo *philo)
//{
//	int	eat_n_meals;

//	if (sem_wait(philo->table->sem_eat_n_meals) == -1)
//		return (ft_put_error(SEM_WAIT_ERROR), 0);
//	eat_n_meals = philo->eat_n_meals;
//	if (sem_post(philo->table->sem_eat_n_meals) == -1)
//		return (ft_put_error(SEM_POST_ERRPR), 0);
//	return (eat_n_meals);
//}

size_t	ft_sem_get_time_start(t_table *table)
{
	size_t	time_start;

	if (sem_wait(table->sem_time_start) == -1)
		return (ft_put_error(SEM_WAIT_ERROR), 0);
	time_start = table->time_start;
	if (sem_post(table->sem_time_start) == -1)
		return (ft_put_error(SEM_POST_ERRPR), 0);
	return (time_start);
}

size_t	ft_sem_get_time_last_meal(t_philo *philo)
{
	size_t	time_last_meal;

	if (sem_wait(philo->table->sem_time_last_meal) == -1)
		return (ft_put_error(SEM_WAIT_ERROR), 0);
	time_last_meal = philo->time_last_meal;
	if (sem_post(philo->table->sem_time_last_meal) == -1)
		return (ft_put_error(SEM_POST_ERRPR), 0);
	return (time_last_meal);
}

void	ft_sem_set_time_last_meal(t_philo *philo)
{
	if (sem_wait(philo->table->sem_time_last_meal) == -1)
		return (ft_put_error(SEM_WAIT_ERROR));
	philo->time_last_meal = ft_time_cur_ms();
	if (sem_post(philo->table->sem_time_last_meal) == -1)
		return (ft_put_error(SEM_POST_ERRPR));
}
