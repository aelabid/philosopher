/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:59:25 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/27 17:59:35 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

static int	ft_check_number(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

static void	ft_init(int *i, long long *num, int *pos)
{
	*i = 0;
	*num = 0;
	*pos = 0;
}

int	ft_atoi(const char *c)
{
	int			i;
	long long	num;
	int			pos;

	ft_init(&i, &num, &pos);
	while ((c[i] == ' ') || (c[i] == '\f') || (c[i] == '\n')
		|| (c[i] == '\r') || (c[i] == '\t') || (c[i] == '\v'))
		i++;
	if (((c[i] == '-') || (c[i] == '+')))
	{
		if (c[i] == '-')
			pos++;
		i++;
	}
	if ((c[i] >= '0') && (c[i] <= '9'))
	{
		while (ft_check_number(c[i]) == 1)
		{
			num = num * 10 + c[i] - '0';
			i++;
		}
	}
	if (pos != 0)
		num = num * -1;
	return (num);
}
