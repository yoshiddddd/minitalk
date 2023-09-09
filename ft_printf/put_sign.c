/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:53:32 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/21 16:14:10 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sign(t_flag *flag, int nbr)
{
	int	nbr_sign;

	nbr_sign = 1;
	if (nbr < 0)
		nbr_sign = -1;
	if (flag->plus == 1)
	{
		if (nbr_sign == 1)
			return (ft_putchar('+'));
		else
			return (ft_putchar('-'));
	}
	else if (flag->space == 1)
	{
		if (nbr_sign == 1)
			return (ft_putchar(' '));
		else
			return (ft_putchar('-'));
	}
	if (nbr_sign == -1)
		return (ft_putchar('-'));
	return (0);
}

int	check_sign(int nbr, t_flag *flag)
{
	int	count;
	int	nbr_sign;

	count = 0;
	nbr_sign = 1;
	if (nbr < 0)
		nbr_sign = -1;
	if (flag->plus == 1)
	{
		if (nbr_sign == 1)
			count++;
		else
			count++;
	}
	else if (flag->space == 1)
	{
		if (nbr_sign == 1)
			count++;
		else
			count++;
	}
	else if (nbr_sign == -1)
		count++;
	return (count);
}
