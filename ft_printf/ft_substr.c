/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:22:06 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 17:04:47 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	char	*s2;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	s2 = (char *)s;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (ans == NULL)
		return (NULL);
	while (k < start && s2[k] != '\0')
		k++;
	while (i < len && s2[k] != '\0')
	{
		ans[i] = s2[k];
		i++;
		k++;
	}
	ans[i] = '\0';
	return (ans);
}
