/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:10:11 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 21:48:09 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*s;
	unsigned char	*d;

	x = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (x < n)
	{
		d[x] = s[x];
		if (s[x] == (unsigned char)c)
			return (dst + x + 1);
		x++;
	}
	return (NULL);
}
