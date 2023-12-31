/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:27:01 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/09/09 18:07:19 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	signal_handler(int signum)
{
	static int	i;
	char		c;
	static int	bit_char = 0;

	bit_char = bit_char << 1;
	if (signum == SIGUSR1)
		bit_char |= 1;
	else if (signum == SIGUSR2)
		bit_char |= 0;
	i++;
	c = 0xff & bit_char;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

void	exit_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
		exit_error("argc Error\nTry again ./server\n");
	ft_printf("PID : %d\n", getpid());
	sig.sa_handler = signal_handler;
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
