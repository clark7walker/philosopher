/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cltan <cltan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:06:25 by cltan             #+#    #+#             */
/*   Updated: 2026/06/02 10:05:45 by cltan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	size_t			no_philo;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	long			p_die;
	long			p_sleep;
	long			p_eat;
	int				running;
	long			start_time;
	pthread_mutex_t	run_lock;
	pthread_mutex_t	print_lock;
	int				no_philo_eat;
}				t_table;

typedef struct s_philo
{
	int				phi_id;
	long			last_ate;
	int				phi_eaten;
	pthread_mutex_t	meal_lock;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_table			*table;
}					t_philo;

int		ft_valid_args(int argc, char **argv);
long	ft_strtol(const char *s, char **endptr);
void	ft_error_args(void);
void	ft_error(void);
int		init_table(t_table *table, int argc, char **argv);
int		ft_init_philo(int no_philo, t_philo *philo, t_table *table);
long	get_time_ms(void);
void	ft_free_table(t_table *table);
void	ft_destroy_mutex(t_table *table);
void	ft_partial_destroy(t_table *table, int forks, int meals);
int		ft_simulation(t_table *table);
void	*ft_routine(void *arg);
int		ft_running(t_table *table);
void	*ft_monitor(void *arg);
int		ft_check_death(t_table *table);
int		ft_check_full(t_table *table);
void	ft_print(t_philo *philo, char *msg);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

#endif