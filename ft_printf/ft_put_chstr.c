/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:09:51 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:42 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s, int writelen)
{
	int	i;

	i = 0;
	if (writelen == -1)
		writelen = (int)ft_strlen(s);
	if (writelen < 0)
		writelen = writelen * -1;
	while (s[i] != '\0' && writelen > 0)
	{
		write(1, &s[i], 1);
		i++;
		writelen--;
	}
	return (i);
}
