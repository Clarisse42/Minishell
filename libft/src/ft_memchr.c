/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:58:51 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 21:59:16 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*str;

	x = 0;
	str = (unsigned char *)s;
	while (x < n)
	{
		if (str[x] == (unsigned char)c)
			return (str + x);
		x++;
	}
	return (NULL);
}
