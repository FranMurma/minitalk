/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:51:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/01 16:51:48 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "client.h"

static void	ft_to_binary(int pid_nb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << (7 - bit))) == 0)
		{
			if (kill(pid_nb, SIGUSR1) == -1)
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
		}
		else
		{
			if (kill(pid_nb, SIGUSR2) == -1)
			{
				write(1, "Error\n", 6);
				exit(-1);
			}
		}
		bit++;
		usleep(100);
	}
}

static void	ft_send_chars(int pid_nb, char **argv)
{
	int				count;
	unsigned char	c;

	count = 0;
	while (argv[2][count])
	{
		c = argv[2][count];
		ft_to_binary(pid_nb, c);
		count++;
	}
}

int	main(int argc, char **argv)
{
	int	pid_nb;

	if (ft_check_errors_c(argc, argv) == -1)
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	pid_nb = ft_mini_atoi(argv[1]);
	ft_send_chars(pid_nb, argv);
	return (0);
}	
