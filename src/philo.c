/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   philo.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 00:42:41 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/03/22 01:08:37 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	table->state_locks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	while (i < table->philo_nb)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->state_locks[i], NULL);
		i++;
	}
}

int	main(int argn, char **argv)
{
	t_table	table;

	if (argn != 5 && argn != 6)
		return (0);
	table.philo_nb = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (argn == 6)
		table.iterations = ft_atoi(argv[5]);
}
