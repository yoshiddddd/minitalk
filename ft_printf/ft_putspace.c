/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:06:17 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/21 16:05:33 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putspace(int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		count += ft_putchar(' ');
		len--;
	}
	return (count);
}
