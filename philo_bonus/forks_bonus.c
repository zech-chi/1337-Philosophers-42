/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:07:43 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 14:56:22 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_forks_up(t_philo *philo)
{
	if (sem_wait(philo->table->sem_forks) == -1)
		return (ft_put_error(SEM_WAIT_ERROR), FAILED);
	ft_put_action(ft_time_1(philo->table), philo, TAKE_FORK);
	if (sem_wait(philo->table->sem_forks) == -1)
		return (ft_put_error(SEM_WAIT_ERROR), FAILED);
	ft_put_action(ft_time_1(philo->table), philo, TAKE_FORK);
	return (SUCCESS);
}

int	ft_forks_down(t_philo *philo)
{
	if (sem_post(philo->table->sem_forks) == -1)
		return (ft_put_error(SEM_POST_ERRPR), FAILED);
	if (sem_post(philo->table->sem_forks) == -1)
		return (ft_put_error(SEM_POST_ERRPR), FAILED);
	return (SUCCESS);
}
