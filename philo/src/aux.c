/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   aux.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 01:09:15 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/09 12:14:48 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	wait(long long time, t_philo *philo)
{
	long long	wait_start;

	wait_start = get_current_time();
	while (get_current_time() < wait_start + time)
	{
		pthread_mutex_lock(philo->state_lock);
		if (philo->state == DEAD)
		{
			pthread_mutex_unlock(philo->state_lock);
			return ;
		}
		pthread_mutex_unlock(philo->state_lock);
	}
}

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

long long	get_passed_time(t_philo *philo)
{
	return (get_current_time() - philo->start_timestamp);
}

int	is_philo_dead(t_philo *philo)
{
	if (philo->iterations != 0)
		return (get_current_time() - philo->ate >= philo->time_to_die);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	numb;

	while (*str == ' ')
		str ++;
	numb = 0;
	while (*str >= '0' && *str <= '9')
	{
		numb *= 10;
		numb += *str - '0';
		str ++;
	}
	if (*str == '\0')
		return (numb);
	else
		exit(1);
}
