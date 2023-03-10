/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:10:27 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/30 16:26:00 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "client.h"

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
