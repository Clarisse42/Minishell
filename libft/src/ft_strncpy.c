/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 19:51:35 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 22:22:36 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t x;

	x = 0;
	while (x < len && src[x] != '\0')
	{
		dst[x] = src[x];
		x++;
	}
	while (x < len)
	{
		dst[x] = '\0';
		x++;
	}
	return (dst);
}
