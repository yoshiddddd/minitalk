/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:51:45 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 16:12:56 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_write(t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->minus == 1)
	{
		count += ft_putchar('%');
		count += ft_putspace(flag->width - count);
	}
	else
	{
		if (flag->zero == 0)
			count += ft_putspace(flag->width - 1);
		else
			count += put_zeros(flag->width - 1);
		count += ft_putchar('%');
	}
	return (count);
}
