/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 09:04:59 by cltan             #+#    #+#             */
/*   Updated: 2026/06/02 13:17:07 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (ft_running(philo->table))
	{
		printf("%ld %d %s\n", (get_time_ms() - philo->table->start_time),
			(philo->phi_id + 1), msg);
	}
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	ft_eat(t_philo *philo)
{
	int	first;
	int	second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(&philo->table->fork[first]);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->fork[second]);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_ate = get_time_ms();
	philo->phi_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	usleep(philo->table->p_eat * 1000);
	pthread_mutex_unlock(&philo->table->fork[first]);
	pthread_mutex_unlock(&philo->table->fork[second]);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	usleep(philo->table->p_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	long	think_time;

	ft_print(philo, "is thinking");
	think_time = philo->table->p_die - philo->table->p_eat
		- philo->table->p_sleep;
	if (think_time > 0)
		usleep((think_time / 2) * 1000);
}
