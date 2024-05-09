/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:01:23 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 11:31:52 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_philos_create(t_table *table)
{
	table->philos_pid = malloc(sizeof(pid_t) * table->n_philosophers);
	if (!table->philos_pid)
	{
		ft_put_error(MALLOC_ERROR);
		return (FAILED);
	}
	return (SUCCESS);
}
