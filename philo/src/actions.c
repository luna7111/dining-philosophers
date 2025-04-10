/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   actions.c                                      .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/04/05 12:35:24 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/10 22:20:58 by ldel-val          ``                     */
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
	pthread_mutex_lock(philo->state_lock);
	pthread_mutex_lock(philo->print_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is thinking\n", get_passed_time(philo), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	pthread_mutex_unlock(philo->state_lock);
	if (philo->laterality == RIGHT_HANDED && philo->philo_nb % 2)
		wait(1, philo);
}

void	eslip(t_philo *philo)
{
	pthread_mutex_lock(philo->print_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is sleeping\n", get_passed_time(philo), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	wait(philo->time_to_sleep, philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->state_lock);
	pthread_mutex_lock(philo->print_lock);
	if (philo->state == ALIVE)
		printf("%lld %d is eating\n", get_passed_time(philo), philo->id);
	pthread_mutex_unlock(philo->print_lock);
	philo->ate = get_current_time();
	pthread_mutex_unlock(philo->state_lock);
	wait(philo->time_to_eat, philo);
}
