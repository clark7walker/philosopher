/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:10:59 by cltan             #+#    #+#             */
/*   Updated: 2026/05/16 20:18:22 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_strtol(const char *s, char **endptr)
{
	int		i;
	long	n;
	
	n = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = (n * 10) + (s[i] - '0');
		i++;
	}
	if (endptr)
		*endptr = (char *)(s + i);
	return (n);
}

int	ft_valid_args(int argc, char **argv)
{
	int		i;
	long	nb;
	char	*end;

	i = 0;
	while (++i < argc)
	{
		nb = ft_strtol(argv[i], &end);
		if (*end != '\0' || nb <= 0 || nb > 2147483647)
			return (0);
	}
	return (1);
}