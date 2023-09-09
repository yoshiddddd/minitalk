/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sharp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:33:12 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/06/21 16:13:59 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sharp(t_flag *flag, unsigned int nbr, char ident)
{
	int	count;

	count = 0;
	if (flag->sharp == 1 && nbr != 0)
	{
		if (ident == 'x')
			count += ft_putstr("0x", 2);
		else
			count += ft_putstr("0X", 2);
	}
	return (count);
}

int	get_sharp(t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->sharp == 1)
		count += 2;
	return (count);
}
