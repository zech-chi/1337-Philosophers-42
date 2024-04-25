/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:04:37 by zech-chi          #+#    #+#             */
/*   Updated: 2024/04/25 12:38:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (
		c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\f'
	);
}

static int	ft_atoi_plus(char *str, int *error)
{
	long long	res;
	int			i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (*error = 1, 0);
	i = i + (str[i] == '+');
	if (!str[i])
		return (*error = 1, 0);
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 2147483647)
			return (*error = 1, 0);
	}
	if (str[i])
		return (*error = 1, 0);
	return (res);
}

int	ft_parse_data(t_data *table, int ac, char **av)
{
	int	error;

	if (ac < 5 || ac > 6)
		return (1);
	error = 0;
	table->n_philosopher = ft_atoi_plus(av[1], &error);
	table->time_to_die = ft_atoi_plus(av[2], &error);
	table->time_to_eat = ft_atoi_plus(av[3], &error);
	table->time_to_sleep = ft_atoi_plus(av[4], &error);
	if (ac == 6)
		table->max_meals = ft_atoi_plus(av[5], &error);
	else
		table->max_meals = -1;
	if (error)
		ft_put_error(PARSING_ERROR);
	return (error);
}
