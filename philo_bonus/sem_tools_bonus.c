/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:59:11 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:37:47 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(char *file_name, int counter, int *error)
{
	sem_t	*s;

	s = sem_open(file_name, O_CREAT, 0644, counter);
	if (s == SEM_FAILED)
		*error = 1;
	return (s);
}

size_t	ft_sem_get_time_start(t_philo *philo)
{
	size_t	time_start;

	if (sem_wait(philo->table->sem_time_start) == -1)
		return (0);
	time_start = philo->table->time_start;
	if (sem_post(philo->table->sem_time_start) == -1)
		return (0);
	return (time_start);
}

size_t	ft_sem_get_time_last_meal(t_philo *philo)
{
	size_t	time_last_meal;

	if (sem_wait(philo->table->sem_time_last_meal) == -1)
		return (0);
	time_last_meal = philo->time_last_meal;
	if (sem_post(philo->table->sem_time_last_meal) == -1)
		return (0);
	return (time_last_meal);
}

void	ft_sem_set_time_last_meal(t_philo *philo, size_t cur_time)
{
	if (sem_wait(philo->table->sem_time_last_meal) == -1)
		return ;
	philo->time_last_meal = cur_time;
	if (sem_post(philo->table->sem_time_last_meal) == -1)
		return ;
}
