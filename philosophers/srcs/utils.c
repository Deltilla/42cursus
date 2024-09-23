#include <philo.h>

void ph_print(char *str, t_philo *philo, int name)
{
    int time;

    pthread_mutex_lock(&philo->data->dead_lock);
    time = get_cur_time - philo->data->start_time;
    if (!dead_loop(philo))
        pritf("%d %d %s\n", time, name, str);
}

int get_cur_time(void)
{
    struct timeval  time;

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