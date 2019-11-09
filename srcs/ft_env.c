/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:16:09 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 18:55:05 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_error(char **s)
{
	size_t	i;

	i = 0;
	if (!ft_strcmp(s[i], "env"))
	{
		ft_putstr_base(s[i], 2);
		ft_putstr_base(": ", 2);
		ft_putstr_base(s[i + 1], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	if (!ft_strcmp(s[i], "setenv"))
	{
		ft_putstr_base(s[i], 2);
		ft_putstr_base(": ", 2);
		ft_putstr_base("not an identifier: ", 2);
		ft_putendl_fd(s[i + 1], 2);
	}
	return (0);
}

size_t			ft_env(char **input, t_dict *envs)
{
	t_dict	*env;
	size_t	i;

	i = 0;
	env = envs;
	if (ft_2d_strlen(input) == 1)
	{
		while (env != NULL)
		{
			ft_putstr_base(env->key, 1);
			ft_putstr_base("=", 1);
			ft_putendl(env->value, 0);
			env = env->next;
		}
	}
	else if (*input[1] != '-')
	{
		ft_error(input);
	}
	return (0);
}

static void		add_env_key(size_t is_key, t_dict *tmp_env,
								t_dict *env, char **input)
{
	if (is_key == 1)
	{
		ft_strdel(&tmp_env->value);
		tmp_env->value = ft_strdup("");
		add_envp_value(input[1], input[2]);
	}
	else
	{
		push_back_pair(&env, new_pair(ft_strjoin(
						input[1], "="), 1));
		add_envp(input[1], input[2]);
	}
}

static void		add_env_key_value(size_t is_key, t_dict *tmp_env,
						t_dict *env, char **input)
{
	if (is_key == 1)
	{
		if (ft_strcmp(tmp_env->value, input[2]) != 0)
		{
			ft_strdel(&tmp_env->value);
			tmp_env->value = ft_strdup(input[2]);
			add_envp_value(input[1], input[2]);
		}
	}
	else
	{
		push_back_pair(&env, new_pair(ft_strjoin_chr(
						input[1], input[2], '='), 1));
		add_envp(input[1], input[2]);
	}
}

size_t			ft_setenv(char **input, t_dict *envs, t_dict **bins)
{
	t_dict	*env;
	t_dict	*tmp_env;
	size_t	is_key;
	size_t	len;

	env = envs;
	len = ft_2d_strlen(input);
	if (len == 1)
		ft_env(input, envs);
	else
	{
		if (!ft_isalpha(*input[1]))
			return (ft_error(input));
		is_key = key_present(&env, input[1]);
		tmp_env = get_dict_elem(&env, input[1]);
		if (len == 2 && input[1] != NULL)
			add_env_key(is_key, tmp_env, env, input);
		else if (len == 3 && input[1] != NULL &&
				ft_isalpha(*input[1]) == 1 && input[2] != NULL)
			add_env_key_value(is_key, tmp_env, env, input);
		if (ft_strequ(input[1], "PATH"))
			bins_dict(bins, envs);
	}
	return (0);
}
