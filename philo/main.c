/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:37:09 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/05 22:47:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (ft_parsing(&table, ac, av))
		return (FAILED);
	if (ft_table_init(&table))
		return (FAILED);
	ft_simulation(&table);
	printf("The END\n");
	return (0);
}
