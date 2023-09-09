/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:51:09 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 19:20:53 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_minus_process(t_flag *flag, char *hex, unsigned int i,
		char ident)
{
	int	count;

	count = 0;
	count += put_sharp(flag, i, ident);
	count += put_zeros((flag->precision - getnbr_base_len(i, hex, flag)));
	ft_putnbr_base((unsigned long long)i, hex, &count, flag);
	count += ft_putspace(flag->width - count);
	return (count);
}

static int	ft_hex_notminus_process(t_flag *flag, char *hex, unsigned int i,
		char ident)
{
	int	count;
	int	zerocount;

	count = 0;
	zerocount = 0;
	if (flag->zero == 0 || (flag->zero == 1 && flag->precision >= 0)
		|| (flag->zero == 0 && flag->precision == 0))
	{
		zerocount = flag->precision - getnbr_base_len(i, hex, flag);
		if (zerocount < 0)
			zerocount = 0;
		count += ft_putspace(flag->width - zerocount - getnbr_base_len(i, hex,
					flag) - get_sharp(flag));
		count += put_sharp(flag, i, ident);
		count += put_zeros((flag->precision - getnbr_base_len(i, hex, flag)));
	}
	else
	{
		count += put_sharp(flag, i, ident);
		count += put_zeros((flag->width - getnbr_base_len(i, hex, flag)
					- get_sharp(flag)));
	}
	ft_putnbr_base(i, hex, &count, flag);
	return (count);
}

int	ft_hex_write(unsigned int i, char ident, t_flag *flag)
{
	char	*hex;
	int		count;

	count = 0;
	if (ident == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (flag->minus == 1)
		count += ft_hex_minus_process(flag, hex, i, ident);
	else
		count += ft_hex_notminus_process(flag, hex, i, ident);
	return (count);
}
