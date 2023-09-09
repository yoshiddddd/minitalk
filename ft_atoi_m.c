/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/09/09 10:37:02 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_parsenumber(const char *str, int flag)
{
	long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if ((num > LONG_MAX / 10 && flag == 1) || (num == LONG_MAX / 10 && (*str
					+ 1) - '0' > LONG_MAX % 10 && flag == 1))
		{
			write(1, "Error\nover [LONG_MAX]", 21);
			exit(EXIT_FAILURE);
		}
		else if ((num > LONG_MAX / 10 && flag == -1) || (num == LONG_MAX / 10
				&& (*str + 1) - '0' > (LONG_MIN % 10) * -1 && flag == -1))
		{
			write(1, "Error\nover [LONG_MAX]", 21);
			exit(EXIT_FAILURE);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	if (flag == -1)
		num *= -1;
	return ((int)num);
}

long	ft_atoi_m(const char *str)
{
	int	flag;
	long	num;

	num = 0;
	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		flag *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = ft_parsenumber(str, flag);
	return (num);
}
