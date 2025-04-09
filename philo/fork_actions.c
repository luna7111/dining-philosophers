/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   fork_actions.c                                     :+:      :+:    :+:   */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/04/06 22:40:10 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/07 18:50:22 by ldel-val         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (philo_check_state(philo) == ALIVE)
	{
		pthread_mutex_lock(philo->print_lock);
		printf("%lld %d has taken a fork\n", get_passed_time(philo), philo->id);
		pthread_mutex_unlock(philo->print_lock);
	}
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (philo_check_state(philo) == ALIVE)
	{
		pthread_mutex_lock(philo->print_lock);
		printf("%lld %d has taken a fork\n", get_passed_time(philo), philo->id);
		pthread_mutex_unlock(philo->print_lock);
	}
}

void	leave_forks(t_philo *philo)
{
	if (philo->laterality == LEFT_HANDED)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}
