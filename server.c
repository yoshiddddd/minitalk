/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:27:01 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/09/06 13:12:36 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	struct sigaction	sa1;
	struct sigaction	sa2;

	printf("PID : %d\n", getpid());
	// memset(&sa1, 0, sizeof(sigaction));
	// memset(&sa2, 0, sizeof(sigaction));
	sa1.sa_handler = signal_handler;
	sa2.sa_handler = signal_handler;
	sigemptyset(&sa1.sa_mask);	
	sigemptyset(&sa2.sa_mask);
	// sa1.sa_sigaction = signal_handler;
	// sa2.sa_sigaction = signal_handler;
	// sigaddset(&sa1.sa_mask, SIGUSR2);
	// sigaddset(&sa2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &sa1, NULL) != 0)
		exit_error("sigaction error");
	if (sigaction(SIGUSR2, &sa2, NULL) != 0)
		exit_error("sigaction error");
	while (1)
		pause();
}
