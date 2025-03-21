/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   philo.c                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 00:42:41 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/03/22 00:54:54 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argn, char **argv)
{
	t_table	table;

	if (argn != 5 && argc != 6)
		return (0);
	table.philo_nb = argv[1];
	table.time_to_die = argv[2];
	table.time_to_eat = argv[3];
	table.time_to_sleep = argv[4];
	if (argn == 6)
		table.iterations = argv[5];
}
