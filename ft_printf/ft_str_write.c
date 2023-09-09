/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:49:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:49 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_write(char *s, t_flag *flag)
{
	int	count;

	count = 0;
	if (s == NULL)
		s = "(null)";
	if (flag->precision > (int)ft_strlen(s))
		flag->precision = (int)ft_strlen(s);
	if (flag->minus == 1)
	{
		count += ft_putstr(s, flag->precision);
		count += ft_putspace(flag->width - count);
	}
	else
	{
		if (flag->precision == -1)
			flag->precision = (int)ft_strlen(s);
		if (flag->zero == 1)
			count += put_zeros(flag->width - flag->precision);
		else
			count += ft_putspace(flag->width - flag->precision);
		count += ft_putstr(s, flag->precision);
	}
	return (count);
}
