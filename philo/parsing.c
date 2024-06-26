/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:43:59 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/22 08:47:08 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (
		c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\f' || c == '\v'
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
		return (*error = 1, -1);
	i += (str[i] == '+');
	if (!str[i])
		return (*error = 1, -1);
	res = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 2147483647)
			return (*error = 1, -1);
	}
	if (str[i])
		return (*error = 1, -1);
	return (res);
}

static void	ft_print_invalid_args(t_table *table, int ac, char **av)
{
	if (table->n_philosophers == -1)
	{
		ft_put_on_stderr(av[1]);
		ft_put_on_stderr(" <-- n_philosophers: invalid\n");
	}
	if (table->time_to_die == -1)
	{
		ft_put_on_stderr(av[2]);
		ft_put_on_stderr(" <-- time_to_die: invalid\n");
	}
	if (table->time_to_eat == -1)
	{
		ft_put_on_stderr(av[3]);
		ft_put_on_stderr(" <-- time_to_eat: invalid\n");
	}
	if (table->time_to_sleep == -1)
	{
		ft_put_on_stderr(av[4]);
		ft_put_on_stderr(" <-- time_to_sleep: invalid\n");
	}
	if (ac == 6 && table->max_meals == -1)
	{
		ft_put_on_stderr(av[5]);
		ft_put_on_stderr(" <-- max_meals: invalid\n");
	}
}

static int	ft_check_valid_args(t_table *table)
{
	if (table->n_philosophers > 200)
	{
		ft_put_error(PARSING_ERROR);
		ft_put_on_stderr("Do not test with more than 200 philosophers.\n");
		return (FAILED);
	}
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
	{
		ft_put_error(PARSING_ERROR);
		ft_put_on_stderr("Do not test with time_to_die or time_to_eat ");
		ft_put_on_stderr("or time_to_sleep set to values lower than 60 ms.\n");
		return (FAILED);
	}
	return (SUCCESS);
}

int	ft_parsing(t_table *table, int ac, char **av)
{
	int	error;

	if (ac < 5 || ac > 6)
	{
		ft_put_error(PARSING_ERROR);
		ft_put_on_stderr("the number of arguments must be between 4 and 5\n");
		return (FAILED);
	}
	error = 0;
	table->n_philosophers = ft_atoi_plus(av[1], &error);
	table->time_to_die = ft_atoi_plus(av[2], &error);
	table->time_to_eat = ft_atoi_plus(av[3], &error);
	table->time_to_sleep = ft_atoi_plus(av[4], &error);
	if (ac == 6)
		table->max_meals = ft_atoi_plus(av[5], &error);
	else
		table->max_meals = -2;
	if (error)
	{
		ft_put_error(PARSING_ERROR);
		ft_print_invalid_args(table, ac, av);
		return (FAILED);
	}
	return (ft_check_valid_args(table));
}
