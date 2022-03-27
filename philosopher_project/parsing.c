/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:48:53 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/27 19:15:44 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_error(char *str)
{
	printf("%s", str);
	exit(1);
}


static void	parsing(int ac, char **av, t_philo *philo)
{
	if (ac > 6 || ac < 5)
		ft_error("problem in arguments");
	philo->nb_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_eat = ft_atoi(av[4]);
	else
		philo->nb_eat = -1;
}

void	check_args(char **av, int ac, t_philo *philo)
{
	parsing(ac, av, philo);
	if (ac == 6 && philo->nb_eat <= 0)
		ft_error("number of times each philosopher must eat wrong");
	if (philo->time_to_die < 0)
		ft_error("time to die wrong");
	if (philo->time_to_eat < 0)
		ft_error("time eat wrong");
	if (philo->time_to_sleep < 0)
		ft_error("time to sleep wrong");
}