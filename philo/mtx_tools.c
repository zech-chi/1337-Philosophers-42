/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:38:54 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:10:54 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mtx_lock(t_table *table, pthread_mutex_t *mtx_ptr)
{
	if (pthread_mutex_lock(mtx_ptr))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_mtx_unlock(t_table *table, pthread_mutex_t *mtx_ptr)
{
	if (pthread_mutex_unlock(mtx_ptr))
	{
		ft_mtx_set_stop(table);
		return (FAILED);
	}
	return (SUCCESS);
}
