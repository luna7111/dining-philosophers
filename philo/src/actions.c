/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   actions.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/04/05 12:35:24 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/12 17:29:52 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_check_state(t_philo *philo)
{
	int	state;

	state = philo->state;
	return (state);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(philo->main_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is thinking\n", get_passed_time(philo), philo->id);
	pthread_mutex_unlock(philo->main_lock);
	if (philo->laterality == RIGHT_HANDED && philo->philo_nb % 2)
		wait(1, philo);
}

void	eslip(t_philo *philo)
{
	pthread_mutex_lock(philo->main_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is sleeping\n", get_passed_time(philo), philo->id);
	pthread_mutex_unlock(philo->main_lock);
	wait(philo->time_to_sleep, philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->main_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is eating\n", get_passed_time(philo), philo->id);
	philo->ate = get_current_time();
	pthread_mutex_unlock(philo->main_lock);
	wait(philo->time_to_eat, philo);
}
