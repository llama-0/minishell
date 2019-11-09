/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:26:01 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 17:05:14 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		iterate_ij(size_t *l, size_t *j)
{
	(*l)++;
	(*j)++;
}

static char		*ft_helper(t_dict *envs, char *tmp, char *s, size_t flag)
{
	t_dict	*env;
	size_t	l;
	size_t	j;

	env = envs;
	while (env != NULL)
	{
		l = 0;
		j = (size_t)(tmp - s) + 1;
		while (env->key[l] != '\0' && env->key[l] == s[j])
			iterate_ij(&l, &j);
		if (env->key != NULL && ft_strlen(env->key) == l)
		{
			if (*s == '~' && *(s + 1) == '$')
				return (ft_tilda_env(s, env->value, envs, flag));
			if (*s == '~' && *(s + 1) != '$')
				return (ft_rubbish_at_start(s, env->value, flag, j));
			if (*s == '~' && !is_a_dir(env->value))
				return (ft_tilda_rubbish_dir(s, s[j], env->value, flag));
			if (*s != '~' && s[j] == '\0')
				return (ft_interior_no_tilda(s, tmp, env->value));
		}
		env = env->next;
	}
	return (ft_leftovers(s, tmp, envs, flag));
}

static char		*ft_tilda(char **res_str, char *s, t_dict *envs, size_t flag)
{
	char	*tmp;

	if (ft_strlen(s) == 1)
	{
		if (flag == 0)
			return (*res_str = ft_only_current_dir(envs, s));
		else
			return (*res_str = ft_strdup("~"));
	}
	if (ft_strlen(s) == 2 && *(s + 1) == '$')
		return (*res_str = ft_strdup(s));
	if (*(s + 1) == '/')
		return (tilda_slash(res_str, s, envs));
	if ((tmp = ft_strchr(s, '$')) == NULL)
	{
		if (flag == 0)
			return (*res_str = ft_strdup(s + 1));
		else
			return (*res_str = ft_strdup(s));
	}
	return (*res_str = ft_helper(envs, tmp, s, flag));
}

static void		quoted(char **s, int *flag)
{
	char	*tmp;

	tmp = ft_strndup(*s + 1, ft_strlen(*s) - 2);
	ft_strcpy(*s, tmp);
	ft_strdel(&tmp);
	*flag = 1;
}

char			**ft_substitute_vars(char **s, t_dict *envs)
{
	char	*tmp_chr;
	char	**tmp;
	size_t	i;
	int		flag;

	i = 0;
	tmp = (char **)ft_memalloc(sizeof(char *) * (ft_2d_strlen(s) + 1));
	flag = 0;
	while (s[i] != NULL)
	{
		if (*s[i] == '"')
			quoted(&s[i], &flag);
		if (ft_strcmp(s[i], "$") == 0)
			tmp[i] = ft_strdup("$");
		else if (*s[i] == '~')
			tmp[i] = ft_tilda(&tmp[i], s[i], envs, flag);
		else if (*s[i] == '\'')
			tmp[i] = ft_strndup(s[i] + 1, ft_strlen(s[i]) - 2);
		else if ((tmp_chr = ft_strchr(s[i], '$')) != NULL)
			tmp[i] = ft_helper(envs, tmp_chr, s[i], flag);
		else
			tmp[i] = ft_strdup(s[i]);
		i++;
	}
	return (tmp);
}
