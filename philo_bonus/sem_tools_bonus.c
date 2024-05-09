/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:59:11 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/09 12:35:58 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(char *file_name, int counter, int *error)
{
	sem_t	*s;

	s = sem_open(file_name, O_CREAT, 0644, counter);
	if (s == SEM_FAILED)
	{
		ft_put_error(SEM_OPEN_ERROR);
		*error = 1;
	}
	return (s);
}
