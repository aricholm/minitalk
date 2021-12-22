/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:00:10 by aricholm          #+#    #+#             */
/*   Updated: 2021/12/22 15:24:43 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

static void	handle_sigusr(int signal, siginfo_t *siginfo, void *v)
{
	static unsigned char	input = 0;
	static unsigned char	mask = 0b10000000;

	(void)v;
	if (mask)
	{
		input += mask * (signal == SIGUSR1);
		mask = mask >> 1;
	}
	if (!mask)
	{
		write(1, &input, 1);
		if (!input)
			kill(siginfo->si_pid, SIGUSR2);
		mask = 0b10000000;
		input = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s1;

	ft_printf("The servers process ID is: %d\n", getpid());
	s1.sa_flags = SA_SIGINFO;
	s1.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	while (1)
		pause();
	return (0);
}
