/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:18:48 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 17:47:06 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	parsing(t_info *info, int ac, char **av)
{
	info->nb_philo = ft_atoi(av[1]);
	info->t_to_die = ft_atoi(av[2]);
	info->t_to_eat = ft_atoi(av[3]);
	info->t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->n_of_must_eat = ft_atoi(av[5]);
}

void	check_info(t_info *info, int ac)
{
	if (ac == 6 && info->n_of_must_eat <= 0)
		ft_error("Num of must eat wrong\n");
	if (info->nb_philo < 0)
		ft_error("Num of philosophers wrong\n");
	if (info->t_to_die < 0)
		ft_error("time to die wrong\n");
	if (info->t_to_eat < 0)
		ft_error("time to eat wrong\n");
	if (info->t_to_sleep < 0)
		ft_error("time to sleep wrong\n");
}

void	initialise_philos(t_philo *philos, t_info *info)
{
	int		i;

	pthread_mutex_init(&info->m_stop, NULL);
	pthread_mutex_init(&info->msg, NULL);
	pthread_mutex_init(&info->last_eat, NULL);
	i = 0;
	while (i < info->nb_philo)
	{
		philos[i].info = info;
		philos[i].id = i + 1;
		philos[i].n = info->nb_philo;
		philos[i].count = 0;
		philos[i].stop = 0;
		philos[i].t_die = info->t_to_die;
		philos[i].t_eat = info->t_to_eat;
		philos[i].t_sleep = info->t_to_sleep;
		philos[i].nb_must_eat = info->n_of_must_eat;
		i++;
	}	
}

void	init(t_info *info, int ac, char **av)
{
	parsing(info, ac, av);
	check_info(info, ac);
}
