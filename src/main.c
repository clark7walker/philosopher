/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:39:30 by cltan             #+#    #+#             */
/*   Updated: 2026/05/16 20:43:21 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments.\n");
		return (1);
	}
	if (!ft_valid_args(argc, argv))
		return (ft_error_args(), 1);
	if (!init_table(&table, argc, argv))
		return (ft_error(), 1);
	
	return 0;	
}
