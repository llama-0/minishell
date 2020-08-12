#include "minishell.h"

/*
** This parse-helper func extracts a string, corresponding to PATH env variable
** aka PATH=/Users/...:/...:/...
*/

char	*ft_path(t_dict *envs)
{
	t_dict	*env;

	env = envs;
	while (env != NULL)
	{
		if (ft_strequ(env->key, "PATH"))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

char	*ft_only_current_dir(t_dict *envs, char *s)
{
	t_dict	*tmp;
	char	*res;

	res = s;
	tmp = envs;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, "HOME") == 0)
		{
			res = ft_strdup(tmp->value);
			return (res);
		}
		tmp = tmp->next;
	}
	return (ft_strdup(res));
}
