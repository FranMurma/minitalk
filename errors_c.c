/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:54:11 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/30 19:32:02 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "client.h"

static int	ft_error_nb(char **argv)
{
	int	c2;

	c2 = 0;
	while (argv[1][c2])
	{
		if (argv[1][c2] >= '0' && argv[1][c2] <= '9')
		{
			c2++;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

int	ft_check_errors_c(int argc, char **argv)
{
	if (argc != 3)
	{
		return (-1);
	}
	else if (ft_error_nb(argv) == -1)
		return (-1);
	return (0);
}
