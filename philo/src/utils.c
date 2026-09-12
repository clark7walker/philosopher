/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:26:41 by cltan             #+#    #+#             */
/*   Updated: 2026/05/17 15:10:58 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_args(void)
{
	printf("Invalid arguments.\n");
}

void	ft_error(void)
{
	printf("Error.\n");
}

void	ft_free_table(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->fork)
		free(table->fork);
}

void	ft_destroy_mutex(t_table *table)
{
	int	n;

	n = (int)(table->no_philo);
	ft_partial_destroy(table, n, n);
}

void	ft_partial_destroy(t_table *table, int forks, int meals)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->run_lock);
	while (++i < forks)
		pthread_mutex_destroy(&table->fork[i]);
	while (++j < meals)
		pthread_mutex_destroy(&table->philo[j].meal_lock);
}
