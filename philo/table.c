/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:01:46 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/04 16:09:17 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table_mtx_destroy(t_table *table)
{
	int	error;

	error = SUCCESS;
	if (pthread_mutex_destroy(&(table->mtx_n_philosophers)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_time_to_die)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_time_to_eat)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_time_to_sleep)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_max_meals)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_start)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_stop)))
		error = FAILED;
	if (pthread_mutex_destroy(&(table->mtx_time_start)))
		error = FAILED;
	if (error == FAILED)
		ft_put_error(MUTEX_DESTROY_ERROR);
	return (error);
}

int	ft_table_mtx_init(t_table *table)
{
	int	error;

	error = SUCCESS;
	if (pthread_mutex_init(&(table->mtx_n_philosophers), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_time_to_die), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_time_to_eat), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_time_to_sleep), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_max_meals), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_start), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_stop), NULL))
		error = FAILED;
	if (pthread_mutex_init(&(table->mtx_time_start), NULL))
		error = FAILED;
	if (error == FAILED)
		ft_put_error(MUTEX_CREAT_ERROR);
	return (error);
}

int	ft_table_init(t_table *table)
{
	table->philos = NULL;
	table->mtx_forks = NULL;
	if (ft_table_mtx_init(table))
	{
		ft_table_mtx_destroy(table);
		return (FAILED);
	}
	ft_forks_create(table);
	ft_forks_init(table);
	
	return (SUCCESS);
}
