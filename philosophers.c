/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:12:53 by aelabid           #+#    #+#             */
/*   Updated: 2022/04/01 17:47:37 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	main(int ac, char **av)
{
	t_info			info;
	t_philo			*philos;
	pthread_t		*thread;
	pthread_mutex_t	*forks;

	if (ac != 5 && ac != 6)
		ft_error("problem in args");
	init(&info, ac, av);
	philos = malloc(sizeof(t_philo) * info.nb_philo);
	thread = malloc(sizeof(pthread_t) * info.nb_philo);
	forks = malloc(sizeof(pthread_mutex_t) * info.nb_philo);
	if (!philos || !thread || !forks)
		ft_error("malloc problem\n");
	initialise_philos(philos, &info);
	distribute_forks(philos, forks, info.nb_philo);
	launch_threads(philos, &info, thread);
	destroy_free(philos, thread, &info, forks);
	exit (0);
}
