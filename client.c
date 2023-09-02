/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:35:54 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/09/01 11:04:56 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_char(int pid, char c)
{
    int     bit;
    bit = 0;
    while(bit < 8)
    {
        if(c&(1<<bit))
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        bit++;
        usleep(100);
    }
}

void    send_str(const pid_t pid ,char *str)
{
    while(*str)
    {
        send_char(pid,*str);
        str++;
    }
}

int main(int argc , char **argv)
{
    int     pid;
    if(argc!=3)
    {
        printf("Error\n");
        printf("Try again ./client [PID] [SEND_MSG]\n");
        return 1;
    }
    pid = atoi(argv[1]);
    send_str(pid,argv[2]);
}