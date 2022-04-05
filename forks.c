/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:10:19 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 17:46:39 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	distribute_forks(t_philo *philos, pthread_mutex_t *forks, int n)
{
	int	i;

	pthread_mutex_init(&forks[0], NULL);
	philos[0].l_f = &forks[0];
	philos[0].r_f = &forks[n - 1];
	i = 1;
	while (i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		philos[i].l_f = &forks[i];
		philos[i].r_f = &forks[i - 1];
		i++;
	}
}
