/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:18:47 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/31 17:15:22 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "server.h"

static void	ft_get_signals(int signal)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	c = c << 1;
	if (signal == SIGUSR1)
	{
	}
	else
		c = c | 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = '\0';
	}
}

static void	ft_print_pid(void)
{
	int	pid_nb;

	pid_nb = getpid();
	if (!pid_nb)
	{
		write(1, "Error.\nI cannot give the PID number", 35);
		return ;
	}
	ft_putnbr(pid_nb);
}

int	main(int argc, char **argv)
{
	write(1, "\n", 1);
	(void)argv;
	if (argc != 1)
	{
		write(1, "Error.\nInvalid number of parameters", 35);
		return (0);
	}
	ft_print_pid();
	write (1, "\n", 1);
	signal(SIGUSR1, &ft_get_signals);
	signal(SIGUSR2, &ft_get_signals);
	while (1)
		pause();
	return (0);
}
