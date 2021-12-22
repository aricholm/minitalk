/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:48:00 by aricholm          #+#    #+#             */
/*   Updated: 2021/12/22 15:24:54 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

static void	waiting(void)
{
	while (g_unread)
		;
	g_unread = TRUE;
}

static void	handle_sigusr(int signal)
{
	if (signal == SIGUSR1)
		g_unread = FALSE;
	else
	{
		write(1, "Message recieved.\n", 19);
		exit(EXIT_SUCCESS);
	}
}

static void	send_message(const int spid, const char *s)
{
	unsigned char	mask;
	size_t			i;

	i = 0;
	while (s[i])
	{
		mask = 0b10000000;
		while (mask)
		{
			if (s[i] & mask)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			waiting();
			mask = mask >> 1;
		}
		i++;
	}
	while (mask < 8)
	{
		kill(spid, SIGUSR2);
		waiting();
		mask++;
	}
}

static t_bool	is_pid(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int argc, const char *argv[])
{
	struct sigaction	s1;
	int					spid;

	if (argc != 3 || !is_pid(argv[1]))
	{
		write(1, "Usage: ./client <SPID> \"message\"\n", 34);
		return (EXIT_FAILURE);
	}
	spid = ft_atoi(argv[1]);
	s1.sa_flags = SA_SIGINFO;
	s1.sa_handler = handle_sigusr;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	send_message(spid, argv[2]);
	while (1)
		pause();
	return (0);
}
