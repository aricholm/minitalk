/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:34:10 by aricholm          #+#    #+#             */
/*   Updated: 2021/11/05 14:47:11 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE 1
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../printf/ft_printf.h"

volatile t_bool	g_unread = TRUE;

#endif