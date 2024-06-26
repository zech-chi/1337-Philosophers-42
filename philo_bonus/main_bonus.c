/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:10:11 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 09:40:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (ft_parsing(&table, ac, av))
		return (FAILED);
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
