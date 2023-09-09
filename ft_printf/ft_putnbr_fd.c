/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/20 20:40:53 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, t_flag *flag, int *count)
{
	long	i;

	i = (long)n;
	if (i < 0)
		i *= -1;
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, flag, count);
		ft_putnbr_fd(i % 10, flag, count);
	}
	else
	{
		*count += ft_putchar(i + '0');
	}
}
