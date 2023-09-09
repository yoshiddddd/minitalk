/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:20:14 by kyoshida          #+#    #+#             */
/*   Updated: 2023/09/08 12:08:17 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(250);
	}
}

void	send_str(const pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
}

void receive(int signal)
{
	(void)signal;
	printf("received!\n");
}

int	main(int argc, char **argv)
{
	long	pid;

	signal(SIGUSR1,receive);
	if (argc != 3)
	{
		printf("Error\n");
		printf("Try again ./client [PID] [SEND_MSG]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	send_char(pid, '\n');
}
