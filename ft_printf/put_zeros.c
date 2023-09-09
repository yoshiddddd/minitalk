/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_zeros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:06:09 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/21 16:14:16 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_zeros(int len)
{
	int	count;

	count = 0;
	if (len < 0)
		return (0);
	while (len > 0)
	{
		count += ft_putchar('0');
		len--;
	}
	return (count);
}
