/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <asousa-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:12:57 by asousa-l          #+#    #+#             */
/*   Updated: 2022/09/12 11:34:20 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void ft_send_msg(int pid, char *str)
{
    int i;
    int dif;

    i = 0;
    while (str[i])
    {
        if (str[i] != START_CHAR)
            dif = (int)str[i] - START_CHAR;
            while (dif)
            {
                kill(pid, SIGUSR1);
                dif--;
                usleep(80);
            }
            kill(pid, SIGUSR2);
            i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    if (ac != 3)
    {
        ft_printf("wrong number of arguments\n");
        return (0);
    }
    pid = ft_atoi(av[1]);
    ft_send_msg(pid, av[2]);
    return (0);
}
