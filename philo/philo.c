/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:25:19 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/22 18:45:06 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_puterror(void)
{
	write(2, "Error\n", 7);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_parse_data(&data, ac, av))
		return (ft_puterror(), 1);
	ft_print_data(data);
	return (0);
}
