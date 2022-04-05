/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:04:36 by aelabid           #+#    #+#             */
/*   Updated: 2022/04/01 17:44:35 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	destroy_free(t_philo *philos, pthread_t *thread, t_info *info,
			pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->last_eat);
	pthread_mutex_destroy(&info->msg);
	pthread_mutex_destroy(&info->m_stop);
	free(philos);
	free(thread);
	free(forks);
}
