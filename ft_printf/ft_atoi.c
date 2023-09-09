/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:14:50 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 16:27:49 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parsenumber(const char *str, int flag)
{
	long	num;

	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		if (num > LONG_MAX / 10 && flag == 1)
			return ((int)LONG_MAX);
		else if (num > LONG_MAX / 10 && flag == -1)
			return ((int)LONG_MIN);
		else if (num == LONG_MAX / 10 && (*str + 1) - '0' > (LONG_MIN % 10) * -1
			&& flag == -1)
			return ((int)LONG_MIN);
		else if (num == LONG_MAX / 10 && (*str + 1) - '0' > LONG_MAX % 10
			&& flag == 1)
			return ((int)LONG_MAX);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (flag == -1)
		num *= -1;
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	num;

	num = 0;
	flag = 1;
	if (!str)
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	num = ft_parsenumber(str, flag);
	return (num);
}
