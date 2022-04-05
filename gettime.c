/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:17:16 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/31 17:58:53 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	get_time(void)
{
	int				ret;
	struct timeval	time;

	ret = 0;
	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(int ms)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(ms / 10);
}
