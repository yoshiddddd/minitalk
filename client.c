/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:35:54 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/09/09 10:36:45 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(200);
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

int	main(int argc, char **argv)
{
	long	pid;

	if (argc != 3)
	{
		printf("Error\n");
		printf("Try again ./client [PID] [SEND_MSG]\n");
		return (1);
	}
	pid = ft_atoi_m(argv[1]);
	send_str(pid, argv[2]);
	send_char(pid, '\n');
}
