/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:07:44 by aelabid           #+#    #+#             */
/*   Updated: 2022/03/27 20:24:25 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosopher.h"

void	eat()
{
		
}

void	*routin(void *i)
{
	printf("philo %d has created\n", *(int *)(i));
	free(i);
	return(NULL);
}

// void	*init(void *philo)
// {
// 	t_philos	*temp;

// 	temp = philo;
	
// 	eat();
// 	sleep(temp->time_to_sleep);
// 	ft_printf(3);
// }


void	initialise(t_philo *philo)
{
	int	i;

	i = 0;
	philo->philos = malloc(sizeof(t_philos) * philo->nb_philos);
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->nb_philos);
	while (i < philo->nb_philos)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		philo->philos[i].right_fork = &philo->fork[i];
		if (i == 0)
			philo->philos[i].left_fork = &philo->fork[philo->nb_philos - 1];
		else
			philo->philos[i].left_fork = &philo->fork[i - 1];
		i++;
	}
}

void create_philo(int nb_philo, int time_to_sleep)
{
	int	i;
	t_philos *philos =NULL;
	pthread_t thread;

//	philos->time_to_sleep = time_to_sleep;
	gettimeofday(&philos->start_time, NULL);

	i = 0;
	while (i < nb_philo)
	{
		t_philos *temp = malloc(sizeof(t_philos));
		temp = philos;
		pthread_create(&thread, NULL,&routin,temp);
		//pthread_mutex_init(&, NULL);
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(thread, NULL);
		i++;
	}
}

int main(int ac, char **av)
{
	t_philo philo;
	check_args(av, ac, &philo);
	//printf("%d", philo->nb_philos);
	//philo->nb_philos = 3;
	initialise(&philo);
}