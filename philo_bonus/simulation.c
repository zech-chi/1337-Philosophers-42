/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:36:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 10:24:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation(t_table *table)
{
	int	i;
	int	pid;
	int	exit_status;

	exit_status = 0;
	i = -1;
	while (++i < table->n_philosophers)
	{
		pid = fork();
		if (pid < 0)
		{
			// err;
		}
		else if (pid == 0)
		{
			//child
			ft_philo(table, i);
		}
		else
		//parent
		table->philos_pid[i] = pid;
	}
	i = -1;
	while (++i < table->n_philosophers)
	{
		waitpid(table->philos_pid[i], &exit_status, 0);
		//if (exit_status)
		//	kill them all
	}
	return (SUCCESS);
}
