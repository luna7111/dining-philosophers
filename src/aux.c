/* ************************************************************************** */
/*                                                                            */
/*                                                    _.._  .           .     */
/*   aux.c                                          .' .-'`        *          */
/*                                                 /  /       +        *      */
/*   By: ldel-val <ldel-val@student.42madrid.com>  |  |           *           */
/*                                                 \  '.___.;       +         */
/*   Created: 2025/03/22 01:09:15 by ldel-val       '._  _.'   .        .     */
/*   Updated: 2025/03/22 11:59:27 by ldel-val          ``                     */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

int	ft_atoi(char *str)
{
	int sign;
	int numb;

	while (*str == ' ')
		str ++;
	if (*str == '-')
	{
		sign = -1;
		str ++;
	}
	else
		sign = 1;
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
