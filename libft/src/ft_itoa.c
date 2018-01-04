/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:21:35 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/25 21:59:20 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_str_len(int n)
{
	size_t			x;

	x = 1;
	while (n /= 10)
		x++;
	return (x);
}

char				*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	x;

	len = ft_str_len(n);
	x = n;
	if (n < 0)
	{
		x = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = x % 10 + '0';
	while (x /= 10)
		str[--len] = x % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
