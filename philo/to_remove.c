#include "philo.h"

void	ft_print_data(t_table table)
{
	printf("n_philosopher : %d\n", table.n_philosophers);
	printf("time_to_die   : %d\n", table.time_to_die);
	printf("time_to_eat   : %d\n", table.time_to_eat);
	printf("time_to_sleep : %d\n", table.time_to_sleep);
	printf("max_meals     : %d\n", table.max_meals);
	if (!table.philos)
		return ;
	for (int i = 0; i < table.n_philosophers; i++)
	{
		printf("philo_id: %d, ", (table.philos)[i].id_philo);
		printf("id_left_fork <- %d, ", (table.philos)[i].id_left_fork);
		printf("id_right_fork -> %d, ", (table.philos)[i].id_right_fork);
		printf("eat_n_meals: %d\n", (table.philos)[i].eat_n_meals);
	}
}
