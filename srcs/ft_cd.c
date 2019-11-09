/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:50:53 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 17:10:48 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error(char **s, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strcmp(s[0], "cd"))
	{
		if (len <= 2)
		{
			ft_putstr_base(s[i], 2);
			ft_putstr_base(": ", 2);
			ft_putstr_base("not a directory: ", 2);
			ft_putendl_fd(s[i + 1], 2);
		}
		else
		{
			ft_putstr_base(s[i], 2);
			ft_putstr_base(": ", 2);
			ft_putstr_base("string not in pwd: ", 2);
			ft_putendl_fd(s[i + 1], 2);
		}
	}
}

static void	refresh_local_pwd(t_dict *envs, char *pwd)
{
	t_dict	*env_oldpwd;
	t_dict	*env_pwd;
	char	*dirname;
	char	buff[BUFF_SIZE];
	size_t	flag;

	flag = 0;
	env_oldpwd = get_dict_elem(&envs, "OLDPWD");
	env_pwd = get_dict_elem(&envs, "PWD");
	if (ft_strcmp(pwd, ".") == 0 && (flag = 1))
		pwd = ft_strdup(env_pwd->value);
	if (ft_strcmp(pwd, "..") == 0 && (flag = 1))
	{
		dirname = getcwd(buff, sizeof(buff));
		pwd = ft_strdup(dirname);
		dirname = NULL;
	}
	ft_strdel(&env_oldpwd->value);
	env_oldpwd->value = ft_strdup(env_pwd->value);
	ft_strdel(&env_pwd->value);
	env_pwd->value = ft_strdup(pwd);
	if (flag == 1)
		ft_strdel(&pwd);
}

size_t		go_to_dir(char **cmd, t_dict *envs)
{
	t_dict	*elem;
	char	*tmp;
	size_t	len;

	len = ft_2d_strlen(cmd);
	if (len == 2 && ft_strequ(cmd[1], "-"))
	{
		if ((elem = get_dict_elem(&envs, "OLDPWD")))
		{
			tmp = cmd[len - 1];
			cmd[len - 1] = ft_strdup(elem->value);
			ft_strdel(&tmp);
		}
	}
	if (chdir(cmd[len - 1]) == -1)
	{
		file_not_found_error(cmd);
	}
	else
	{
		refresh_local_pwd(envs, cmd[len - 1]);
		return (1);
	}
	return (0);
}

static void	ft_only_cd(t_dict *envs)
{
	char	*val;

	if (chdir(val = (get_dict_elem(&envs, "HOME"))->value) == -1)
		ft_putendl_fd("chdir failed", 2);
	else
		refresh_local_pwd(envs, val);
}

size_t		ft_cd(char **input, t_dict *envs)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_2d_strlen(input);
	if (len == 1)
	{
		if (ft_strcmp(input[i], "cd") == 0)
		{
			ft_only_cd(envs);
		}
	}
	if (input[i + 1] != NULL)
	{
		go_to_dir(input, envs);
		if (len > 2)
			error(input, len);
	}
	return (0);
}
