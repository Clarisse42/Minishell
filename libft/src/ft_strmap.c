/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:10:01 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/21 23:27:13 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		x;

	if (s && f)
	{
		x = 0;
		if (!(str = ft_strsub(s, x, ft_strlen(s))))
			return (0);
		while (str[x])
		{
			str[x] = f(s[x]);
			x++;
		}
		return (str);
	}
	return (NULL);
}
