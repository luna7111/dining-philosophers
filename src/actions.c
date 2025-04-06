/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   actions.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/04/05 12:35:24 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/06 22:41:18 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_check_state(t_philo *philo)
{
	int	state;

	pthread_mutex_lock(philo->state_lock);
	state = philo->state;
	pthread_mutex_unlock(philo->state_lock);
	return (state);
}

void	think(t_philo *philo)
{
	if (philo_check_state(philo) == ALIVE)
	{
		pthread_mutex_lock(philo->print_lock);
		printf("%lld %d is thinking\n", get_passed_time(philo), philo->id);
		pthread_mutex_unlock(philo->print_lock);
	}
}

void	eslip(t_philo *philo)
{
	if (philo_check_state(philo) == ALIVE)
	{
		pthread_mutex_lock(philo->print_lock);
		printf("%lld %d is sleeping\n", get_passed_time(philo), philo->id);
		pthread_mutex_unlock(philo->print_lock);
	}
	usleep(philo->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	if (philo_check_state(philo) == ALIVE)
	{
		pthread_mutex_lock(philo->print_lock);
		printf("%lld %d is eating\n", get_passed_time(philo), philo->id);
		pthread_mutex_unlock(philo->print_lock);
	}
	pthread_mutex_lock(philo->state_lock);
	philo->ate = get_current_time();
	pthread_mutex_unlock(philo->state_lock);
	usleep(philo->time_to_eat * 1000);
}
