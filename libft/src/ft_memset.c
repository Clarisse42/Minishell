/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:29:04 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/24 20:59:27 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tab;

	tab = (unsigned char*)b;
	while (len > 0)
	{
		*tab = (unsigned char)c;
		tab++;
		len--;
	}
	return (b);
}
