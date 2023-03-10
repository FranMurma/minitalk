/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:15:43 by frmurcia          #+#    #+#             */
/*   Updated: 2023/02/01 18:13:36 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <signal.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

//static void	ft_get_signals(int signal)
static void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = '\0';

	(void)context;
	usleep(50);
	c = c << 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
	{
		c = c | 1;
		kill(info->si_pid, SIGUSR1);
	}
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			usleep(200);
			kill(info->si_pid, SIGUSR2);
		}
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
	struct sigaction	msj1;
	struct sigaction	msj2;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error.\nInvalid number of parameters", 35);
		return (0);
	}
	ft_print_pid();
	write (1, "\n", 1);
	msj1.sa_flags = SA_SIGINFO;
	msj1.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &msj1, NULL);
	msj2.sa_flags = SA_SIGINFO;
	msj2.sa_sigaction = ft_handler;
	sigaction(SIGUSR2, &msj2, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
