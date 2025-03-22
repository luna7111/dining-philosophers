/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   routines.c                                     .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 01:57:38 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/03/22 02:35:36 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("im %d!\n", philo->id);
	return (NULL);
}

void	*referee_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("im the referee!\n");
	return (NULL);
}
