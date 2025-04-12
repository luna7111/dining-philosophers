/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   routines.c                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 01:57:38 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/12 17:24:29 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*lonely_philo(t_philo *philo)
{
	printf("%lld 1 has taken a fork\n", get_passed_time(philo));
	while (1)
	{
		pthread_mutex_lock(philo->main_lock);
		if (philo->state == DEAD)
			return (NULL);
		pthread_mutex_unlock(philo->main_lock);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_nb == 1)
		return (lonely_philo(philo));
	while (philo_check_state(philo) == ALIVE && philo->iterations != 0)
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
		if (philo->iterations > 0)
			philo->iterations--;
	}
	return (NULL);
}

void	commit_genocide(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nb)
	{
		table->philos[i].state = DEAD;
		i++;
	}
}

void	*referee_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = -1;
		while (++i < table->philo_nb)
		{
			pthread_mutex_lock(table->main_lock);
			if (get_current_time() - table->philos[i].ate >= table->time_to_die)
			{
				if (table->philos[i].iterations != 0)
					printf("%lld %d died\n", get_passed_time(&table->philos[i]),
						table->philos[i].id);
				commit_genocide(table);
				return (pthread_mutex_unlock(table->main_lock), NULL);
			}
			else
				pthread_mutex_unlock(table->main_lock);
		}
	}
	return (NULL);
}
