/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:56:10 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 21:48:52 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			x;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	x = 0;
	if (n == 0)
		return (dest);
	while (x < n)
	{
		d[x] = s[x];
		x++;
	}
	return (dest);
}
