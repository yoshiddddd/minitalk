/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:50:19 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 16:27:41 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_minus_process(int nbr, t_flag *flag)
{
	int	count;

	count = 0;
	count += put_sign(flag, nbr);
	count += put_zeros((flag->precision - ft_intlen(nbr)));
	if (!(nbr == 0 && flag->precision == 0))
		ft_putnbr_fd(nbr, flag, &count);
	count += ft_putspace(flag->width - count);
	return (count);
}

static int	ft_int_notminus_process(int nbr, t_flag *flag)
{
	int	count;
	int	zerocount;

	count = 0;
	zerocount = 0;
	if (flag->zero == 0 || (flag->zero == 1 && flag->precision >= 0)
		|| (flag->zero == 0 && flag->precision == 0))
	{
		zerocount = flag->precision - ft_intlen(nbr);
		if (zerocount < 0)
			zerocount = 0;
		count += ft_putspace(flag->width - zerocount - ft_intlen(nbr)
				- check_sign(nbr, flag) + (flag->precision == 0 && nbr == 0));
		count += put_sign(flag, nbr);
		count += put_zeros((flag->precision - ft_intlen(nbr)));
	}
	else
	{
		count += put_sign(flag, nbr);
		count += put_zeros((flag->width - ft_intlen(nbr) - check_sign(nbr,
						flag)));
	}
	if (!(nbr == 0 && flag->precision == 0))
		ft_putnbr_fd(nbr, flag, &count);
	return (count);
}

int	ft_int_write(int nbr, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->minus == 1)
		count = ft_int_minus_process(nbr, flag);
	else
		count = ft_int_notminus_process(nbr, flag);
	return (count);
}
