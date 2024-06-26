/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:37:09 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:22:45 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (ft_parsing(&table, ac, av))
		return (FAILED);
	if (!table.n_philosophers || !table.max_meals)
		return (SUCCESS);
	if (ft_table_init(&table))
		return (FAILED);
	if (ft_simulation(&table))
	{
		ft_table_destroy_them_all(&table);
		return (FAILED);
	}
	ft_table_destroy_them_all(&table);
	return (SUCCESS);
}
