/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:07:43 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/08 23:29:07 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_create(t_table *table)
{
	int	n;

	n = table->n_philosophers;
	table->sem_forks = sem_open("/tmp/.forks_sem", O_CREAT, 0644, n);
	if (!table->sem_forks)
	{
		ft_put_error(SEM_OPEN_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}

