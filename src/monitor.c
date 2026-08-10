/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:45:00 by cltan             #+#    #+#             */
/*   Updated: 2026/06/02 10:14:09 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		usleep(1000);
		if (ft_check_death(table) || ft_check_full(table))
		{
			pthread_mutex_lock(&table->run_lock);
			table->running = 0;
			pthread_mutex_unlock(&table->run_lock);
			break ;
		}
	}
	return (NULL);
}

int	ft_check_death(t_table *table)
{
	int	i;

	i = -1;
	while (++i < (int)table->no_philo)
	{
		pthread_mutex_lock(&table->philo[i].meal_lock);
		if ((get_time_ms() - table->philo[i].last_ate) > table->p_die)
		{
			ft_print(&table->philo[i], "died");
			pthread_mutex_unlock(&table->philo[i].meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&table->philo[i].meal_lock);
	}
	return (0);
}

int	ft_check_full(t_table *table)
{
	int	i;

	if (table->no_philo_eat == -1)
		return (0);
	i = -1;
	while (++i < (int)table->no_philo)
	{
		pthread_mutex_lock(&table->philo[i].meal_lock);
		if (table->philo[i].phi_eaten < table->no_philo_eat)
		{
			pthread_mutex_unlock(&table->philo[i].meal_lock);
			return (0);
		}
		pthread_mutex_unlock(&table->philo[i].meal_lock);
	}
	return (1);
}
