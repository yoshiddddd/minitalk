/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:20:26 by kyoshida          #+#    #+#             */
/*   Updated: 2023/09/06 18:21:49 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_char = 0;

void	signal_handler(int signum, siginfo_t *info, void *dummy)
{
	static int	i;
	char		c;

	if (info || dummy)
		;
	g_char = g_char << 1;
	if (signum == SIGUSR1)
		g_char |= 1;
	else if (signum == SIGUSR2)
		g_char |= 0;
	i++;
	c = 0xff & g_char;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

void	exit_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	main(void)
{
	struct sigaction sig;

	printf("PID : %d\n", getpid());
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (1)
	{
		if (sigaction(SIGUSR1, &sig, NULL) != 0)
			exit_error("sigaction error");
		if (sigaction(SIGUSR2, &sig, NULL) != 0)
			exit_error("sigaction error");
		pause();
	}
	return (0);
}