/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   routines.c                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 01:57:38 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/06 22:37:33 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo_check_state(philo) == ALIVE)
	{
		if (philo->laterality == LEFT_HANDED)
		{
			take_left_fork(philo);
			take_right_fork(philo);
		}
		else
		{
			take_right_fork(philo);
			take_left_fork(philo);
		}
		eat(philo);
		leave_forks(philo);
		eslip(philo);
		think(philo);
	}
	return (NULL);
}

void	commit_genocide(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		pthread_mutex_lock(table->philos[i].state_lock);
		table->philos[i].state = DEAD;
		pthread_mutex_unlock(table->philos[i].state_lock);
		i++;
	}
}

void	*referee_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (69)
	{
		i = 0;
		while (i < table->philo_nb)
		{
			pthread_mutex_lock(table->philos[i].state_lock);
			if (get_current_time() - table->philos[i].ate >= table->time_to_die)
			{
				pthread_mutex_unlock(table->philos[i].state_lock);
				commit_genocide(table);
				printf("%lld %d died\n", get_passed_time(&table->philos[i]),
					table->philos[i].id);
				return (NULL);
			}
			else
				pthread_mutex_unlock(table->philos[i].state_lock);
			i ++;
		}
	}
	return (NULL);
}
