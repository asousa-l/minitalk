/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <asousa-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:12:57 by asousa-l          #+#    #+#             */
/*   Updated: 2022/11/18 10:22:00 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	the_end(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2)
	{
		ft_printf("message delivered\n");
		exit(0);
	}
}

static void	ft_send_msg(int pid, int c)
{
	int	counter;

	counter = 1 << 6;
	while (counter)
	{
		if (counter & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter >>= 1;
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;
	int					i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	act.sa_sigaction = the_end;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	pid = ft_atoi(av[1]);
	while (av[2][i])
		ft_send_msg(pid, av[2][i++]);
	ft_send_msg(pid, 0);
	return (0);
}
