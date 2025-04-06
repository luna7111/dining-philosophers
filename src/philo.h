/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   philo.h                                        .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/21 23:49:19 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/04/06 23:43:55 by ldel-val          ``                     */
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
# include <pthread.h>
//multithreading

# define INFINITE -1
# define ALIVE 0
# define DEAD 1
# define FINISHED 2
# define LEFT_HANDED 0
# define RIGHT_HANDED 1

typedef struct s_philo
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				iterations;
	int				id;
	int				philo_nb;
	int				state;
	int				laterality;
	long long		ate;
	long long		start_timestamp;
	pthread_mutex_t	*print_lock;
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
	long long		start_timestamp;
	t_philo			*philos;
	pthread_t		*philo_threads;
	pthread_t		referee_thread;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*state_locks;
}	t_table;

int			philo_check_state(t_philo *philo);
void		eat(t_philo	*philo);
void		eslip(t_philo	*philo);
void		think(t_philo	*philo);
void		take_left_fork(t_philo *philo);
void		take_right_fork(t_philo *philo);
void		leave_forks(t_philo *philo);

long long	get_current_time(void);
long long	get_passed_time(t_philo *philo);
int			is_philo_dead(t_philo *philo);
int			ft_atoi(char *str);

void		*philo_routine(void *philo);
void		*referee_routine(void *table);
#endif
