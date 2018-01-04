/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:20:46 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 05:17:02 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_prompt(void)
{
	char		*buffer;
	char		*user;

	user = getenv("USER");
	if (user == NULL)
		user = "";
	buffer = malloc(ft_strlen(user) + 100);
	if (buffer != NULL)
	{
		ft_strcpy(buffer, "\033[34m");
		ft_strcat(buffer, user);
		ft_strcat(buffer, "\033[0m in \033[31m");
		ft_strcat(buffer, "Minishell\n");
		ft_strcat(buffer, "\033[34m|\n");
		ft_strcat(buffer, "|__››› \033[0m");
	}
	return (buffer);
}
