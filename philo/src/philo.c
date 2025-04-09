/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   philo.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 00:42:41 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/09 11:39:32 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	init_mutexes(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	table->state_locks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	table->print_lock = malloc(sizeof(pthread_mutex_t));
	i = 0;
	pthread_mutex_init(table->print_lock, NULL);
	while (i < table->philo_nb)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->state_locks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->philo_nb);
	i = -1;
	while (++i < table->philo_nb)
	{
		table->philos[i].time_to_eat = table->time_to_eat;
		table->philos[i].time_to_sleep = table->time_to_sleep;
		table->philos[i].time_to_die = table->time_to_die;
		table->philos[i].iterations = table->iterations;
		table->philos[i].philo_nb = table->philo_nb;
		table->philos[i].start_timestamp = table->start_timestamp;
		table->philos[i].ate = table->start_timestamp;
		table->philos[i].state = ALIVE;
		table->philos[i].id = i + 1;
		table->philos[i].print_lock = table->print_lock;
		table->philos[i].laterality = LEFT_HANDED;
		if (i % 2 == 0)
			table->philos[i].laterality = RIGHT_HANDED;
		table->philos[i].state_lock = &(table->state_locks[i]);
		table->philos[i].right_fork = &(table->forks[i]);
		table->philos[i].left_fork = &(table->forks[i - 1]);
		if (i == 0)
			table->philos[i].left_fork = &(table->forks[table->philo_nb - 1]);
	}
}

void	init_threads(t_table *table)
{
	int	i;

	table->philo_threads = malloc(sizeof(pthread_t) * table->philo_nb);
	i = 0;
	while (i < table->philo_nb)
	{
		pthread_create(&(table->philo_threads[i]), NULL, philo_routine,
			(void *)&(table->philos[i]));
		i++;
	}
	pthread_create(&(table->referee_thread), NULL, referee_routine,
		(void *)table);
	pthread_join(table->referee_thread, NULL);
	while (i > 0)
	{
		i--;
		pthread_join(table->philo_threads[i], NULL);
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
	else
		table.iterations = INFINITE;
	table.start_timestamp = get_current_time();
	init_mutexes(&table);
	init_philosophers(&table);
	init_threads(&table);
	free(table.philo_threads);
	free(table.philos);
	free(table.forks);
	free(table.state_locks);
	free(table.print_lock);
	return (0);
}
