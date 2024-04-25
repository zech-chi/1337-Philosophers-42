/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:25:19 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 16:33:42 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft(void)
{
	system("leaks philo");
}

	//table->start_time = 0;
void	ft_init_table(t_data *table)
{
	table->philosophers = NULL;
	table->forks = NULL;
	table->dead = 0;
	table->error = 0;
}

/*
	protect pthread_creation failure;
	race condition of data->error;
*/
	//atexit(ft);
int	main(int ac, char **av)
{
	t_data	table;

	if (ft_parse_data(&table, ac, av))
		return (FAILED);
	ft_init_table(&table);
	if (ft_forks_create(&table))
		return (FAILED);
	if (ft_philos_create(&table))
		return (ft_free_them_all(&table), FAILED);
	ft_philos_init(&table);
	ft_print_data(table);
	if (ft_start_simulation(&table))
		return (ft_free_them_all(&table), FAILED);
	return (SUCCESS);
}
