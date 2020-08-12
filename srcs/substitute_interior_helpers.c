#include "minishell.h"

char	*ft_rubbish_at_start(char *s, char *env_value, size_t flag, int j)
{
	char	*tmp;
	char	*res;
	char	*res_final;

	if ((tmp = ft_strchr(s, '$')) - s != 0)
	{
		if (flag == 0)
			res = ft_strndup(s + 1, tmp - s - 1);
		else
			res = ft_strndup(s, tmp - s);
		if (s[j] == '\0' && ((flag == 0 && !is_a_dir(env_value)) ||
							(flag != 0)))
			res_final = ft_strjoin(res, env_value);
		else
			res_final = ft_strdup(res);
		ft_strdel(&res);
		return (res_final);
	}
	return (NULL);
}

char	*ft_interior_no_tilda(char *s, char *tmp, char *env_value)
{
	if (tmp - s != 0)
		return (ft_rubbish_no_tilda(s, tmp, env_value));
	return (ft_strdup(env_value));
}

char	*ft_rubbish_no_tilda(char *s, char *tmp, char *env_value)
{
	char	*res;
	char	*res_final;

	res = ft_strndup(s, tmp - s);
	res_final = ft_strjoin(res, env_value);
	ft_strdel(&res);
	return (res_final);
}

char	*ft_leftovers(char *s, char *tmp, t_dict *envs, size_t flag)
{
	if (*s == '~' && *(s + 1) == '$' && flag == 0)
		return (ft_only_current_dir(envs, s));
	if (*s == '~' && tmp != NULL)
		return (ft_tilda_rubbish(s, tmp, flag));
	if (tmp - s != 0)
		return (ft_strndup(s, tmp - s));
	return (ft_strdup(s));
}
