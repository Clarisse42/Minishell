/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 23:43:02 by ccharuel          #+#    #+#             */
/*   Updated: 2017/09/03 21:16:30 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**g_environ;

static char		**ft_spaces(char *str)
{
	char		*tmp;
	char		**split;

	tmp = str;
	while (*str)
	{
		if (*str == '\n' || *str == '\t' || *str == '\r' || *str == '\b')
			*str = ' ';
		str++;
	}
	split = ft_strsplit(tmp, ' ');
	return (split);
}

static void		main2(int ret, char *buffer, char **av, char *prompt)
{
	ret = 0;
	av = NULL;
	while ((ret = read(0, buffer, 2048)))
	{
		if (ret > 0)
		{
			buffer[ret] = 0;
			av = ft_spaces(buffer);
			ft_heart_prog2(av);
			ft_putstr(prompt);
		}
		ft_free_array(av);
		ft_bzero(buffer, 2048);
	}
}

int				main(void)
{
	char		*buffer;
	char		**av;
	int			ret;
	char		*prompt;

	av = NULL;
	ret = 0;
	prompt = ft_prompt();
	buffer = malloc(sizeof(char) * 2048);
	ft_memset(buffer, 0, 2048);
	write(1, "\e[0;0H\e[2J", sizeof("\e[0;OH\e[2J"));
	ft_putstr(prompt);
	g_environ = ft_cpy_env();
	main2(ret, buffer, av, prompt);
	ft_free_array(g_environ);
	free(buffer);
	free(prompt);
	return (0);
}
