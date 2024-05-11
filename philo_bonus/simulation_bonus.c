/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:36:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/11 19:41:50 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_simulation(t_table *table)
{
	int		i;
	int		pid;
	int		exit_status;
	size_t	time_start;

	time_start = table->time_start;
	exit_status = 0;
	i = -1;
	while (++i < table->n_philosophers)
	{
		pid = fork();
		if (pid < 0)
			;
		else if (pid == 0)
			ft_philo(table, i, time_start);
		table->philos_pid[i] = pid;
	}
	i = -1;
	while (++i < table->n_philosophers)
	{
		pid = waitpid(-1, &exit_status, 0);
		if (exit_status)
			return (ft_kill_them_all(table), SUCCESS);
	}
	return (SUCCESS);
}
