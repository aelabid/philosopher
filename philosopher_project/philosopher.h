/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:08:53 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/27 18:30:44 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos
{
	struct timeval start_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				time_to_sleep;
	struct s_philo	*philo;
} t_philos;

typedef struct s_philo
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	pthread_mutex_t	*fork;
	struct s_philos	*philos;
	
} t_philo;

int		ft_atoi(const char *c);
void	check_args(char **av, int ac, t_philo *philo);
#endif