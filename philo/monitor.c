/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:50:27 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/02 19:26:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static	int	ft_all_philo_full(t_data *table)
//{
//	int	i;

//	i = 0;
//	while (i < table->n_philosopher)
//	{
//		if ((table->philosophers)[i].eat_n_meal != (table->philosophers)[i].max_meals)
//			return (0);
//		i++;
//	}
//	return (1);
//}

static void	*ft_monitor_job(void *arg)
{
	t_data	*table;
	int		i;
	int		count;

	table = (t_data *)arg;
	while (1)
	{
		i = 0;
		count = 0;
		while (i < table->n_philosopher)
		{
			if (ft_get_eat_n_meal(&((table->philosophers)[i])) == ft_get_max_meals(&((table->philosophers)[i])))
				count++;
			else if (ft_diff_time(&(table->philosophers)[i]) > (size_t)table->time_to_die)
			{
				ft_put_action(ft_time(&(table->philosophers)[i]), &(table->philosophers)[i], DIED);
				ft_stop_set(table);
				return (NULL);
			}
			i++;
		}
		if (count == table->n_philosopher)
			break;
		usleep(50);
	}
	return (NULL);
}

int	ft_monitor_thread(t_data *table, pthread_t *th_monitor)
{
	if (pthread_create(th_monitor, NULL, &ft_monitor_job, table))
	{
		ft_put_error(CREAT_THREAD_ERROR);
		table->stop = 1;
		return (FAILED);
	}
	return (SUCCESS);
}
