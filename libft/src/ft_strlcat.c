/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 21:16:06 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/23 03:56:19 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (dst[x] && (x < size))
		x++;
	while (src[y] && (x + y) < (size - 1))
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x < size)
		dst[x + y] = '\0';
	return (x + ft_strlen(src));
}
