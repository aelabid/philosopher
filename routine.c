/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:39:02 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 19:06:26 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(p->r_f);
	pthread_mutex_lock(&p->info->msg);
	ft_print(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->msg);
	if (p->n == 1)
	{
		pthread_mutex_unlock(p->r_f);
		ft_usleep(p->t_die);
		return ;
	}
	pthread_mutex_lock(p->l_f);
	pthread_mutex_lock(&p->info->msg);
	ft_print(p, "has taken a fork");
	pthread_mutex_unlock(&p->info->msg);
	pthread_mutex_lock(&p->info->msg);
	ft_print(p, "is eating");
	pthread_mutex_unlock(&p->info->msg);
	p->count++;
	pthread_mutex_lock(&p->info->last_eat);
	p->t_last_eat = get_time();
	pthread_mutex_unlock(&p->info->last_eat);
	ft_usleep(p->t_eat);
	pthread_mutex_unlock(p->r_f);
	pthread_mutex_unlock(p->l_f);
}

void	do_routine(t_philo *philo)
{
	eat(philo);
	if (philo->nb_must_eat != -1 && philo->count == philo->nb_must_eat)
	{
		pthread_mutex_lock(&philo->info->m_stop);
		philo->stop = 1;
		pthread_mutex_unlock(&philo->info->m_stop);
		return ;
	}
	pthread_mutex_lock(&philo->info->msg);
	ft_print(philo, "is sleeping");
	pthread_mutex_unlock(&philo->info->msg);
	ft_usleep(philo->t_sleep);
	pthread_mutex_lock(&philo->info->msg);
	ft_print(philo, "is thinking");
	pthread_mutex_unlock(&philo->info->msg);
}
