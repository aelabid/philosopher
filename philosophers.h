/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:12:09 by aelabid           #+#    #+#             */
/*   Updated: 2022/04/01 17:44:45 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				nb_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				t_start;
	int				n_of_must_eat;
	int				finish;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	msg;
	pthread_mutex_t	last_eat;
}				t_info;

typedef struct s_philo
{
	t_info			*info;
	int				id;
	int				n;
	int				count;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_must_eat;
	int				t_last_eat;
	int				stop;
	pthread_t		thread;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
}				t_philo;

void	ft_error(char *str);
int		ft_atoi(const char *c);
void	init(t_info *info, int ac, char **av);
void	initialise_philos(t_philo *philos, t_info *info);
void	distribute_forks(t_philo *philos, pthread_mutex_t *forks, int n);
int		get_time(void);
void	do_routine(t_philo *philo);
void	ft_print(t_philo *philo, char *str);
void	ft_usleep(int ms);
int		launch_threads(t_philo *philos, t_info *info, pthread_t *thread);
void	destroy_free(t_philo *philos, pthread_t *thread,
			t_info *info, pthread_mutex_t *forks);
#endif