/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judgment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/07/25 18:50:09 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_flag_check(const char *format, t_flag *flag)
{
	int	i;

	i = 0;
	while (format[i + 1] != '\0')
	{
		if (format[i + 1] == '-')
			flag->minus = 1;
		else if (format[i + 1] == ' ')
			flag->space = 1;
		else if (format[i + 1] == '#')
			flag->sharp = 1;
		else if (format[i + 1] == '+')
			flag->plus = 1;
		else if (format[i + 1] == '0')
			flag->zero = 1;
		else
			break ;
		i++;
	}
	return ((char *)&format[i + 1]);
}

static char	*ft_width_check(const char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;

	i = 0;
	if (format[i] == '*')
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width *= -1;
		}
		return ((char *)&format[i + 1]);
	}
	while ('0' <= format[i] && format[i] <= '9')
		i++;
	chnum = ft_substr(format, 0, i);
	flag->width = ft_atoi(chnum);
	free(chnum);
	chnum = NULL;
	return ((char *)&format[i]);
}

static char	*ft_precision_check(const char *format, va_list args, t_flag *flag)
{
	int		i;
	char	*chnum;

	i = 0;
	if (format[i] == '.')
	{
		if (format[i + 1] == '*')
		{
			flag->precision = va_arg(args, int);
			if (flag->precision < 0)
				flag->precision = -1;
			return ((char *)&format[i + 2]);
		}
		while ('0' <= format[i + 1] && format[i + 1] <= '9')
			i++;
		chnum = ft_substr(format, 1, i);
		flag->precision = ft_atoi(chnum);
		free(chnum);
		chnum = NULL;
		i++;
	}
	return ((char *)&format[i]);
}

static int	ft_check(char ident, va_list args, t_flag *flag)
{
	int	count;

	count = 0;
	if (ident == 'c')
		count = ft_char_write(va_arg(args, int), flag);
	else if (ident == 's')
		count = ft_str_write(va_arg(args, char *), flag);
	else if (ident == 'd' || ident == 'i')
		count = ft_int_write(va_arg(args, int), flag);
	else if (ident == 'p')
		count = ft_ptr_write((unsigned long long)va_arg(args, void *), flag);
	else if (ident == 'u')
		count = ft_uns_write(va_arg(args, unsigned int), flag);
	else if (ident == 'x' || ident == 'X')
		count = ft_hex_write(va_arg(args, unsigned int), ident, flag);
	else if (ident == '%')
		count = ft_percent_write(flag);
	return (count);
}

int	ft_judgment(va_list args, const char *format)
{
	int		count;
	t_flag	*flag;
	t_flag	flag_init;

	count = 0;
	while (*format != '\0')
	{
		flag_init = ft_flag_init();
		flag = &flag_init;
		if (*format == '%')
		{
			format = ft_flag_check(format, flag);
			format = ft_width_check(format, args, flag);
			format = ft_precision_check(format, args, flag);
			count += ft_check(*format, args, flag);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
