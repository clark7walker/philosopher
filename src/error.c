/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:26:41 by cltan             #+#    #+#             */
/*   Updated: 2026/05/16 20:01:53 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error_args()
{
	printf("Invalid arguments.\n");
}

void	ft_error()
{
	printf("Error.\n");
}

void	free_table(t_table *table)
{
	free(table);
}