/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:02:18 by cltan             #+#    #+#             */
/*   Updated: 2026/05/16 21:06:58 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	int	philos;
	
	philos = (int)(ft_strtol(argv[1], NULL));
	table->philos = malloc(sizeof(t_philo)*philos);
	if (!table->philos)
		return (0);
	table->p_die = (int)(ft_strtol(argv[2], NULL));
	table->p_eat = (int)(ft_strtol(argv[3], NULL));
	table->p_sleep = (int)(ft_strtol(argv[4], NULL));
	if (argc == 6)
		table->no_philo_eat = (int)(ft_strtol(argv[5], NULL));
	else
		table->no_philo_eat = -1;
	return (1);
}
