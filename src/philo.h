/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   philo.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/21 23:49:19 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/03/22 00:19:51 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
//usleep
# include <stdio.h>
//printf
# include <stdlib.h>
//memory allocation
# include <sys/time.h>
//gettimeofday
# include <phtread.h>
//multithreading

# define INFINITE -1
# define ALIVE 0
# define DEAD 1
# define FINISHED 2

typedef struct s_philo
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				iterations;
	int				id;
	int				philo_nb;
	int				state;
	long long		ate;
	long long		start_timestamp;
	pthread_mutex_t	*state_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_table
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				iterations;
	int				philo_nb;
	t_philo			*philos;
	pthread_t		*philo_threads;
	pthread_t		referee;
	pthread_mutex_t	*forks;
}	t_table;

#endif
