/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:02:04 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 21:54:44 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	x;
	char	*tmp;

	s = (char *)src;
	d = (char *)dst;
	x = 0;
	tmp = (char *)malloc(sizeof(src) * len);
	if (tmp == NULL)
		return (dst);
	while (x < len)
	{
		tmp[x] = s[x];
		x++;
	}
	x = 0;
	while (x < len)
	{
		d[x] = tmp[x];
		x++;
	}
	free(tmp);
	return (dst);
}
