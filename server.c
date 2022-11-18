/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <asousa-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:26:33 by asousa-l          #+#    #+#             */
/*   Updated: 2022/11/18 10:21:15 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_receive_msg(int sig, siginfo_t *info, void *context)
{
	static int	len;
	static int	byte;
	int			bit;

	(void)context;
	bit = (sig == SIGUSR1);
	byte = byte << 1;
	byte += bit;
	if (++len == 7)
	{
		if (!byte)
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR2);
		}
		ft_putchar_fd(byte, 1);
		len = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %u\n", getpid());
	ft_memset(&act, '\0', sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_receive_msg;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
