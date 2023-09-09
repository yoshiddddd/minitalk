/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:49:36 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 15:49:42 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_write(int args, t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->minus == 1)
	{
		count += ft_putchar((char)args);
		count += ft_putspace(flag->width - 1);
	}
	else
	{
		count += ft_putspace(flag->width - 1);
		count += ft_putchar((char)args);
	}
	return (count);
}
