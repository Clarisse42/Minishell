/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:50:30 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/23 22:30:54 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	int				y;
	char			*str;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (0);
	if (s && f)
	{
		x = 0;
		y = ft_strlen((char*)s);
		while (s[x])
		{
			str[x] = f(x, s[x]);
			x++;
		}
		return (str);
	}
	return (NULL);
}
