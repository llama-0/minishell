#include "minishell.h"

void	add_envp_value(char *key, char *value)
{
	extern char	**environ;
	char		**tmp;
	char		*cmp;
	size_t		i;

	i = 0;
	tmp = environ;
	cmp = ft_strjoin(key, "=");
	while (tmp[i] != NULL)
	{
		if (ft_strnequ(tmp[i], cmp, ft_strlen(cmp)))
		{
			ft_strdel(&cmp);
			ft_strdel(&tmp[i]);
			if (value == NULL)
				value = "";
			tmp[i] = ft_strjoin_chr(key, value, '=');
			break ;
		}
		i++;
	}
}

void	add_envp(char *key, char *value)
{
	extern char	**environ;
	char		**tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * (ft_2d_strlen(environ) + 2))))
		exit(1);
	while (environ[i] != NULL)
	{
		tmp[i] = environ[i];
		i++;
	}
	if (value == NULL)
		value = "";
	tmp[i++] = ft_strjoin_chr(key, value, '=');
	tmp[i] = NULL;
	free(environ);
	environ = tmp;
}

void	remove_envp(char *key, t_dict *envs, t_dict **bins)
{
	extern char	**environ;
	char		**tmp;
	size_t		i;

	i = 0;
	tmp = environ;
	while (tmp[i] != NULL)
	{
		if (ft_strnequ(tmp[i], key, ft_strlen(key)) &&
				tmp[i][ft_strlen(key)] == '=')
		{
			ft_strdel(&tmp[i]);
			while (tmp[i + 1] != NULL)
			{
				tmp[i] = tmp[i + 1];
				i++;
			}
			tmp[i] = NULL;
			if (ft_strequ(key, "PATH"))
				bins_dict(bins, envs);
		}
		i++;
	}
}

size_t	ft_unsetenv(char **input, t_dict *envs, t_dict **bins)
{
	t_dict	*env;
	t_dict	*tmp_env;
	size_t	i;

	env = envs;
	if (ft_2d_strlen(input) > 1)
	{
		i = 1;
		while (input[i] != NULL)
		{
			if ((tmp_env = get_dict_elem(&env, input[i])) != NULL)
			{
				remove_pair(&env, tmp_env->key);
				remove_envp(input[i], envs, bins);
			}
			i++;
		}
	}
	return (0);
}
