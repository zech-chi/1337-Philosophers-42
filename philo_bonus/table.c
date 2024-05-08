/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:55:57 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/08 23:34:06 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table_init(t_table *table)
{
	table->philos_pid = NULL;
	if (ft_philos_create(table) == FAILED)
		return (FAILED);
	if (ft_forks_create(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	return (SUCCESS);
}

int	ft_table_destroy_them_all(t_table *table)
{
	int	err;

	err = 0;
	err = err - sem_close(table->sem_forks);
	err = err - sem_unlink("/tmp/.forks_sem");
	free(table->philos_pid);
	if (err)
		return (FAILED);
	return (SUCCESS);
}
