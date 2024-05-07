/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:01:46 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/07 17:48:21 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_table_init(t_table *table)
{
	table->philos = NULL;
	table->mtx_forks = NULL;
	if (ft_philos_create(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	if (ft_forks_create(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	if (ft_table_mtx_init(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	if (ft_forks_init(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	if (ft_philos_mtx_init(table) == FAILED)
		return (ft_table_destroy_them_all(table), FAILED);
	ft_philos_init(table);
	table->time_start = ft_time_cur_ms();
	return (SUCCESS);
}

int	ft_table_mtx_init(t_table *table)
{
	if (pthread_mutex_init(&(table->mtx_n_philosophers), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_time_to_die), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_time_to_eat), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_time_to_sleep), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_max_meals), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_start), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_stop), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_time_start), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	if (pthread_mutex_init(&(table->mtx_put_action), NULL))
		return (ft_put_error(MUTEX_CREAT_ERROR), FAILED);
	return (SUCCESS);
}

int	ft_table_mtx_destroy(t_table *table)
{
	if (pthread_mutex_destroy(&(table->mtx_n_philosophers)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_time_to_die)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_time_to_eat)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_time_to_sleep)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_max_meals)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_start)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_stop)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_time_start)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	if (pthread_mutex_destroy(&(table->mtx_put_action)))
		return (ft_put_error(MUTEX_DESTROY_ERROR), FAILED);
	return (SUCCESS);
}

void	ft_table_destroy_them_all(t_table *table)
{
	ft_forks_destroy(table, ft_mtx_get_n_philosophers(table));
	ft_philos_mtx_destroy(table);
	ft_table_mtx_destroy(table);
	free(table->philos);
	free(table->mtx_forks);
}
