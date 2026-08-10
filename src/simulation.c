/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 14:28:17 by cltan             #+#    #+#             */
/*   Updated: 2026/06/02 13:27:30 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_simulation(t_table *table)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	while (++i < (int)table->no_philo)
		pthread_create(&table->philo[i].thread, NULL, ft_routine,
			&table->philo[i]);
	pthread_create(&monitor, NULL, ft_monitor, table);
	i = -1;
	while (++i < (int)table->no_philo)
		pthread_join(table->philo[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo	*curr_philo;

	curr_philo = (t_philo *)arg;
	if (curr_philo->table->no_philo == 1)
	{
		pthread_mutex_lock(&curr_philo->table->fork[curr_philo->left_fork]);
		ft_print(curr_philo, "has taken a fork");
		while (ft_running(curr_philo->table))
			usleep(1000);
		pthread_mutex_unlock(&curr_philo->table->fork[curr_philo->left_fork]);
		return (NULL);
	}
	if (curr_philo->phi_id % 2 == 0)
		usleep(curr_philo->table->p_eat * 500);
	while (ft_running(curr_philo->table))
	{
		ft_eat(curr_philo);
		if (!ft_running(curr_philo->table))
			break ;
		ft_sleep(curr_philo);
		if (!ft_running(curr_philo->table))
			break ;
		ft_think(curr_philo);
	}
	return (NULL);
}

int	ft_running(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->run_lock);
	status = table->running;
	pthread_mutex_unlock(&table->run_lock);
	return (status);
}
