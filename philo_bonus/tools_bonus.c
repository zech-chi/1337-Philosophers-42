/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:44 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:35:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_put_on_stderr(char *msg)
{
	int	i;

	if (!msg)
		return ;
	i = 0;
	while (msg[i])
	{
		write(2, msg + i, 1);
		i++;
	}
}

void	ft_put_error(int error_id)
{
	if (error_id == PARSING_ERROR)
		ft_put_on_stderr("Error: invalid arguments\n");
	else if (error_id == MALLOC_ERROR)
		ft_put_on_stderr("Error: failed to allocate memory\n");
}

int	ft_put_action(size_t time, t_philo *philo, int action)
{
	if (sem_wait(philo->table->sem_put_action) == -1)
		return (FAILED);
	if (action == TAKE_FORK)
		printf("%zu %d has taken a fork\n", time, philo->id_philo + 1);
	else if (action == EAT)
		printf("%zu %d is eating\n", time, philo->id_philo + 1);
	else if (action == SLEEP)
		printf("%zu %d is sleeping\n", time, philo->id_philo + 1);
	else if (action == THINK)
		printf("%zu %d is thinking\n", time, philo->id_philo + 1);
	else if (action == DIED)
		printf("%zu %d died\n", time, philo->id_philo + 1);
	if (action != DIED && sem_post(philo->table->sem_put_action) == -1)
		return (FAILED);
	return (SUCCESS);
}
