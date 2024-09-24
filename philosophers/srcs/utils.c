#include <philo.h>

int	finish_him(char *str, t_data *data)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%s\n", str);
	pthread_mutex_unlock(&data->write_lock);
	return (0);
}

int	ft_atoilong(char *str)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	if (!*str)
		return (0);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		r = (r * 10) + (*str - '0');
		str++;
	}
	r *= sign;
	if (r < -2147483648 || r > 2147483647)
		return (0);
	return (r);
}

void ph_print(char *str, t_philo *philo, int name)
{
    int time;

    pthread_mutex_lock(&philo->data->write_lock);
    time = get_cur_time() - philo->data->start_time;
    if (!dead_loop(philo))
		printf("%d %d %s\n", time, name, str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

int get_cur_time(void)
{
    struct timeval	time;

    if (gettimeofday(&time, NULL) == -1)
        write(2, "gettimeofday() error\n", 22);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int ft_usleep(int ms)
{
    int start;

    start = get_cur_time();
    while ((get_cur_time() - start) < ms)
        usleep(500);
    return (0);
}