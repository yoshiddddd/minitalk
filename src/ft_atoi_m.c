/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/09/09 18:06:59 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int	ft_parsenumber(const char *str, int flag)
{
	long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if ((num > LONG_MAX / 10 && flag == 1) || (num == LONG_MAX / 10 && (*str
					+ 1) - '0' > LONG_MAX % 10 && flag == 1))
		{
			ft_printf("Error\nover [LONG_MAX]\n");
			exit(EXIT_FAILURE);
		}
		else if ((num > LONG_MAX / 10 && flag == -1) || (num == LONG_MAX / 10
				&& (*str + 1) - '0' > (LONG_MIN % 10) * -1 && flag == -1))
		{
			ft_printf("Error\nover [LONG_MAX]\n");
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
	int		flag;
	long	num;

	num = 0;
	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '0')
	{
		ft_printf("PIDerror\n");
		exit(EXIT_FAILURE);
	}
	else if (*str == '+')
		str++;
	num = ft_parsenumber(str, flag);
	return (num);
}
