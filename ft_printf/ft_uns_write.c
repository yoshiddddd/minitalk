/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:51:26 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 19:15:57 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uns_minus_process(t_flag *flag, unsigned int i)
{
	int	count;

	count = 0;
	count += put_zeros((flag->precision - ft_unslen(i)) + (i == 0
				&& flag->precision >= 0));
	ft_putnbr_base((unsigned long long)i, "0123456789", &count, flag);
	count += ft_putspace(flag->width - count);
	return (count);
}

int	ft_uns_write(unsigned int i, t_flag *flag)
{
	int	count;
	int	zerocount;

	count = 0;
	zerocount = 0;
	if (flag->minus == 1)
		count += ft_uns_minus_process(flag, i);
	else
	{
		if (flag->zero == 0 || (flag->zero == 1 && flag->precision >= 0)
			|| (flag->zero == 0 && flag->precision == 0))
		{
			zerocount = flag->precision - ft_unslen(i);
			if (zerocount < 0)
				zerocount = 0;
			count += ft_putspace(flag->width - zerocount - ft_unslen(i)
					+ (i == 0 && flag->precision == 0));
			count += put_zeros(flag->precision - ft_unslen(i) + (i == 0
						&& flag->precision >= 0));
		}
		else
			count += put_zeros((flag->width - ft_unslen(i)));
		ft_putnbr_base((unsigned long long)i, "0123456789", &count, flag);
	}
	return (count);
}
