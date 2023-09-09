/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:50:41 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 15:50:53 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_write(unsigned long long p, t_flag *flag)
{
	int	count;
	int	space_num;

	count = 0;
	space_num = 1;
	getnbr_base(p, "0123456789abcdef", &space_num, flag);
	if (flag->minus == 0)
		count += ft_putspace(flag->width - space_num - 2);
	count += ft_putstr("0x", 2);
	ft_putnbr_base(p, "0123456789abcdef", &count, flag);
	if (flag->minus == 1)
		count += ft_putspace(flag->width - space_num - 2);
	return (count);
}
