/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:17:12 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 17:48:30 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *str)
{
	char	*s;
	int		i;

	s = str;
	i = 0;
	while (s[i])
		i++;
	write(2, str, i);
	exit(1);
}

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->m_stop);
	if (philo->info->finish == 1)
	{
		pthread_mutex_unlock(&philo->info->m_stop);
		return ;
	}
	pthread_mutex_unlock(&philo->info->m_stop);
	printf("%d  %d %s\n", get_time() - philo->info->t_start, philo->id, str);
}
