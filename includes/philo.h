/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:06:25 by cltan             #+#    #+#             */
/*   Updated: 2026/05/16 20:03:40 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table t_table;
typedef struct s_philo t_philo;

typedef struct s_table
{
	size_t			philos;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	size_t			p_die;
	size_t			p_sleep;
	size_t			p_eat;
	int				running;
	long			start_time;
	pthread_mutex_t	run_lock;
	pthread_mutex_t	print_lock;
	int				no_philo_eat;
}					t_table;

typedef struct s_philo
{
	int				phi_id;
	size_t			last_ate;
	pthread_mutex_t	meal_lock;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_table			*table;
}					t_philo;


int		ft_valid_args(int argc, char **argv);
long	ft_strtol(const char *s, char **endptr);
void	ft_error_args();
void	ft_error();
int		init_table(t_table **table, int argc, char **argv);

#endif