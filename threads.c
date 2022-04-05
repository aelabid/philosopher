/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:16:56 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 19:07:57 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*if_dead(void *arg)
{
	t_philo	*philo;
	int		finish;

	philo = arg;
	finish = 0;
	while (finish == 0)
	{
		pthread_mutex_lock(&philo->info->last_eat);
		if (get_time() - philo->t_last_eat >= philo->t_die)
		{
			pthread_mutex_lock(&philo->info->msg);
			ft_print(philo, "died");
			philo->info->finish = 1;
			pthread_mutex_unlock(&philo->info->msg);
		}
		pthread_mutex_unlock(&philo->info->last_eat);
		pthread_mutex_lock(&philo->info->m_stop);
		if (philo->info->finish == 1 || philo->stop == 1)
			finish = 1;
		pthread_mutex_unlock(&philo->info->m_stop);
	}
	return (NULL);
}

void	*routin(void	*arg)
{
	t_philo	*philo;
	int		finish;

	philo = arg;
	philo->t_last_eat = philo->info->t_start;
	pthread_create(&philo->thread, NULL, &if_dead, philo);
	pthread_detach(philo->thread);
	finish = 0;
	if (philo->id % 2 == 0)
		ft_usleep(philo->t_eat);
	while (finish == 0)
	{
		do_routine(philo);
		pthread_mutex_lock(&philo->info->m_stop);
		if (philo->info->finish == 1 || philo->stop == 1)
			finish = 1;
		pthread_mutex_unlock(&philo->info->m_stop);
	}
	return (NULL);
}

int	launch_threads(t_philo *philos, t_info *info, pthread_t *thread)
{
	int	i;

	i = 0;
	info->t_start = get_time();
	while (i < info->nb_philo)
	{
		pthread_create(&thread[i], NULL, routin, &philos[i]);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	return (0);
}
