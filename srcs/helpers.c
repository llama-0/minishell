/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:06:48 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 16:51:41 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This func glues together s1 + chr + s2; for example 'key=value'
*/

char	*ft_strjoin_chr(const char *s1, const char *s2, const char c)
{
	char	*res;
	size_t	len;
	size_t	s1_len;
	size_t	j;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2) + 1;
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res = ft_strncpy(res, s1, s1_len);
	res[s1_len++] = c;
	j = 0;
	while (s1_len < len)
		res[s1_len++] = s2[j++];
	res[s1_len] = '\0';
	return (res);
}

size_t	is_input_rubbish(char **cmd, t_dict *envs, size_t flag)
{
	struct stat	st;

	if ((flag == 0 && stat(cmd[0], &st) < 0) || (flag == 1
				&& stat((get_dict_elem(&envs, "OLDPWD"))->value, &st) < 0))
	{
		if (cmd[0][ft_strlen(cmd[0]) - 1] == '/')
		{
			ft_putstr_base("minishell: not a directory: ", 2);
			ft_putendl_fd(cmd[0], 2);
		}
		else
		{
			ft_putstr_base("minishell: command not found: ", 2);
			ft_putendl_fd(cmd[0], 2);
		}
		return (1);
	}
	if ((access(cmd[0], F_OK) == 0 || access(cmd[0], R_OK) == 0)
			&& S_ISREG(st.st_mode) > 0)
		return (0);
	return (1);
}

size_t	is_a_dir(char *s)
{
	struct stat	st;

	if (stat(s, &st) < 0)
		return (0);
	if (S_ISDIR(st.st_mode))
		return (1);
	return (0);
}

void	file_not_found_error(char **cmd_arr)
{
	ft_putstr_base(cmd_arr[0], 2);
	ft_putstr_base(": ", 2);
	ft_putstr_base("no such file or directory: ", 2);
	ft_putendl_fd(cmd_arr[1], 2);
}
