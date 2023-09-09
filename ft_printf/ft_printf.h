/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:06:55 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 17:18:09 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct flag
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	space;
	int	sharp;
	int	plus;
}		t_flag;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s, int writelen);
void	ft_putnbr_fd(int n, t_flag *flag, int *count);
void	ft_putnbr_base(unsigned long long nb, char *base, int *count,
			t_flag *flag);
int		ft_putspace(int len);
int		put_sign(t_flag *flag, int nbr);
int		put_zeros(int len);
int		put_sharp(t_flag *flag, unsigned int nbr, char ident);
int		ft_judgment(va_list args, const char *format);
int		check_sign(int nbr, t_flag *flag);
t_flag	ft_flag_init(void);
size_t	ft_strlen(const char *s);
int		ft_intlen(int nbr);
int		ft_unslen(unsigned int nbr);
int		ft_atoi(const char *str);
void	getnbr_base(unsigned long long nb, char *base, int *num, t_flag *flag);
int		getnbr_base_len(unsigned int nb, char *base, t_flag *flag);
int		get_sharp(t_flag *flag);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_char_write(int args, t_flag *flag);
int		ft_str_write(char *s, t_flag *flag);
int		ft_int_write(int nbr, t_flag *flag);
int		ft_ptr_write(unsigned long long p, t_flag *flag);
int		ft_hex_write(unsigned int i, char ident, t_flag *flag);
int		ft_uns_write(unsigned int i, t_flag *flag);
int		ft_percent_write(t_flag *flag);
#endif