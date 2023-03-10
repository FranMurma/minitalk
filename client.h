/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:22:05 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/30 16:28:28 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

/* checks */
int		ft_check_errors_c(int argc, char **argv);

/* aux */
int		ft_mini_atoi(const char *str);
#endif
