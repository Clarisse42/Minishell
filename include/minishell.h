/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 06:26:09 by ccharuel          #+#    #+#             */
/*   Updated: 2017/05/12 13:57:47 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include "../libft/include/libft.h"

extern char			**g_environ;

char				*ft_prompt(void);
int					ft_get_path2(char **av, DIR *dir, char **split, char **tmp);
int					ft_execv(char *path, char *cmd, char **av);
void				ft_heart_prog2(char **av);
void				ft_echo(char **v);
void				ft_env();
int					ft_getenv(char *name);
char				*my_getenv(const char *str);
char				**ft_unsetenv(char *name);
int					cmd_setenv(char **av);
int					cmd_unsetenv(char **av);
int					ft_cd(char **av);
char				**ft_add_array(char *str, char **array);
char				**ft_remove_to_array(int rem, char **array);
int					ft_free_array(char **array);
char				*copy(const char *string);
const char			*env_get(const char *str);
size_t				env_count(size_t base);
int					compare(const char *s1, const char *s2);
char				**ft_cpy_array(int rem, char **new_array, char **array,
		int len);
int					ft_array_len(char **array);
char				**ft_cpy_env();
#endif
