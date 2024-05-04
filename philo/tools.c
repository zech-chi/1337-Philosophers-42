/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:21:07 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 12:33:45 by zech-chi         ###   ########.fr       */
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
	else if (error_id == MUTEX_CREAT_ERROR)
		ft_put_on_stderr("Error: failed to create mutex\n");
	else if (error_id == MUTEX_DESTROY_ERROR)
		ft_put_on_stderr("Error: failed to destroy mutex\n");
	else if (error_id == MUTEX_LOCK_ERROR)
		ft_put_on_stderr("Error: failed to lock mutex\n");
	else if (error_id == MUTEX_UNLOCK_ERROR)
		ft_put_on_stderr("Error: failed to unlock mutex\n");
}
