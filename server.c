/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <asousa-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:26:33 by asousa-l          #+#    #+#             */
/*   Updated: 2022/09/12 11:34:01 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    g_c = START_CHAR;

void ft_receive_msg(int sig)
{
    if (sig == SIGUSR1)
        g_c++;
    else
    {
        ft_putchar_fd(g_c, 1);
        g_c = START_CHAR;
    }
}

int main(void)
{
    ft_printf("Server PID: %u\n", getpid());
    signal(SIGUSR1, ft_receive_msg);
    signal(SIGUSR2, ft_receive_msg);
    while (1)
        pause();
    return  (0);
}
