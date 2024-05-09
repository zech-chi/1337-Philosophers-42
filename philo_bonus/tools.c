/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:44 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 10:37:41 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	else if (error_id == CREAT_THREAD_ERROR)
		ft_put_on_stderr("Error: failed to create thread\n");
	else if (error_id == JOIN_THREAD_ERROR)
		ft_put_on_stderr("Error: failed to join thread\n");
	else if (error_id == SEM_OPEN_ERROR)
		ft_put_on_stderr("Error: failed to open sem\n");
	else if (error_id == SEM_CLOSE_ERROR)
		ft_put_on_stderr("Error: failed to close sem\n");
	else if (error_id == SEM_POST_ERRPR)
		ft_put_on_stderr("Error: failed to post sem\n");
	else if (error_id == SEM_WAIT_ERROR)
		ft_put_on_stderr("Error: failed to wait sem\n");
	else if (error_id == SEM_UNLINK_ERROR)
		ft_put_on_stderr("Error: failed to unlink sem\n");
}

void	ft_put_action(size_t time, t_philo *philo, int action)
{
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
}
