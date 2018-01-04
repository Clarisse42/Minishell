/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 23:18:14 by ccharuel          #+#    #+#             */
/*   Updated: 2016/11/25 22:06:22 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	char	*will_be;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(size = ft_strlen((char*)s) - 1))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!*s || size == i - 1)
		return (ft_strnew(1));
	while (size > 0 && (s[size] == ' ' || s[size] == '\n' || s[size] == '\t'))
		size--;
	will_be = ft_strsub(s, (unsigned int)i, (size - i + 1));
	return (will_be);
}
