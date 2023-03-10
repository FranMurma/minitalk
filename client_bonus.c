/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:07:09 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/01 18:03:53 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <signal.h>

int	ft_mini_atoi(const char *str)
{
	int	count;
	int	store;

	count = 0;
	store = 0;
	if (str[count] != '\0')
	{
		while (str[count] >= '0' && str[count] <= '9')
		{
			store = (store * 10) + (str[count] - '0');
			count++;
		}
	}
	return (store);
}

static void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		usleep(50);
		write(1, "Bit confirmed\n", 14);
	}
	else if (signal == SIGUSR2)
	{
		write(1, "Message confirmed\n", 18);
		exit (1);
	}
}

static void	ft_to_binary(int pid_nb, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << (7 - bit))) == 0)
		{
			if (kill(pid_nb, SIGUSR1) == -1)
				write(1, "Error\n", 6);
			signal(SIGUSR1, &ft_handler);
			pause();
		}
		else
		{
			if (kill(pid_nb, SIGUSR2) == -1)
				write(1, "Error\n", 6);
			signal(SIGUSR2, &ft_handler);
			pause();
		}
		bit++;
		usleep(200);
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
	ft_to_binary(pid_nb, argv[2][count]);
}

int	main(int argc, char **argv)
{
	int	pid_nb;
	int	c2;

	c2 = 0;
	if (argc != 3)
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	while (argv[1][c2])
	{
		if (argv[1][c2] >= '0' && argv[1][c2] <= '9')
			c2++;
		else
		{
			write (1, "Error\n", 6);
			exit(1);
		}
	}
	pid_nb = ft_mini_atoi(argv[1]);
	ft_send_chars(pid_nb, argv);
	return (0);
}
