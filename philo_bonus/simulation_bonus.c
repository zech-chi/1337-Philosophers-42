/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:36:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 15:54:31 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_search(t_table *table, pid_t x)
{
	int i;

	i = -1;
	while (++i < table->n_philosophers)
	{
		if (table->philos_pid[i] == x)
			return (i);
	}
	return (-1);
}

//if (exit_status)
//	kill them all
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
			;
		else if (pid == 0)
		{
			ft_philo(table, i);
		}
		table->philos_pid[i] = pid;
	}
	i = -1;
	while (++i < table->n_philosophers)
	{
		pid = waitpid(-1, &exit_status, 0);
		if (exit_status)
		{
			//printf("%d dead\n", ft_search(table, pid) + 1);
			ft_kill_them_all(table);
			break;
		}
	}
	return (SUCCESS);
}
