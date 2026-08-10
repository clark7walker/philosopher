/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:02:18 by cltan             #+#    #+#             */
/*   Updated: 2026/05/17 15:51:04 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	int	philos;

	philos = (int)(ft_strtol(argv[1], NULL));
	table->philo = malloc(sizeof(t_philo) * philos);
	if (!table->philo)
		return (ft_free_table(table), 0);
	table->fork = malloc(sizeof(pthread_mutex_t) * philos);
	if (!table->fork)
		return (ft_free_table(table), 0);
	table->no_philo = philos;
	table->p_die = ft_strtol(argv[2], NULL);
	table->p_eat = ft_strtol(argv[3], NULL);
	table->p_sleep = ft_strtol(argv[4], NULL);
	table->running = 1;
	table->start_time = get_time_ms();
	if (argc == 6)
		table->no_philo_eat = ft_strtol(argv[5], NULL);
	else
		table->no_philo_eat = -1;
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->run_lock, NULL);
	if (!ft_init_philo(philos, table->philo, table))
		return (ft_free_table(table), 0);
	return (1);
}

int	ft_init_philo(int no_philo, t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < no_philo)
	{
		philo[i].phi_id = i;
		philo[i].last_ate = table->start_time;
		philo[i].phi_eaten = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % no_philo;
		philo[i].table = table;
		if (pthread_mutex_init(&table->fork[i], NULL) != 0)
			return (ft_partial_destroy(table, i, i), 0);
		if (pthread_mutex_init(&philo[i].meal_lock, NULL) != 0)
			return (ft_partial_destroy(table, i + 1, i), 0);
		i++;
	}
	return (1);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
