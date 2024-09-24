#include <philo.h>

int philo_dead(t_philo *philo, int die_time)
{
    pthread_mutex_lock(philo->meal_lock);
    if (get_cur_time() - philo->last_meal >= die_time && philo->eating == 0)
    {
        pthread_mutex_unlock(philo->meal_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->meal_lock);
    return (0);
}

int dead_checker(t_data *data)
{
    int i;

    i = -1;
    while (++i < data->num_philos)
    {
        if (philo_dead(&data->philos[i], data->die_time))
        {
            ph_print("died", &data->philos[i], data->philos[i].name);
            pthread_mutex_lock(&data->dead_lock);
            data->philos[i].dead = 1;
            pthread_mutex_unlock(&data->dead_lock);
            return (1);
        }
    }
    return (0);
}

int meals_checker(t_data *data)
{
    int i;
    int philos_full;

    i = -1;
    philos_full = 0;
    if (data->max_meals == INT_MAX)
        return (0);
    while (++i < data->num_philos)
    {
        pthread_mutex_lock(&data->meal_lock);
        if (data->philos[i].meals_eaten >= data->max_meals)
            philos_full++;
        pthread_mutex_unlock(&data->meal_lock);
    }
    if (philos_full == data->num_philos)
    {
        pthread_mutex_lock(&data->dead_lock);
        data->philos[0].dead = 1;
        pthread_mutex_unlock(&data->dead_lock);
        return (1);
    }
    return (0);
}

void    *observing(void *pointer)
{
    t_data *data;

    data = (t_data *)pointer;
    while (!dead_checker(data) && !meals_checker(data))
        ;
    return (NULL);
}