#include "minishell.h"

char	*ft_tilda_env(char *s, char *env_value, t_dict *envs, size_t flag)
{
	char	*start;
	char	*line;
	size_t	dir;

	start = NULL;
	dir = is_a_dir(env_value);
	if (!dir)
	{
		if (flag == 0)
			line = ft_strdup(env_value);
		else
			line = ft_strjoin("~", env_value);
	}
	else
	{
		if (flag == 0)
			start = ft_only_current_dir(envs, s);
		else
			start = ft_strdup("~");
		line = ft_strjoin(start, env_value);
		ft_strdel(&start);
	}
	return (line);
}

char	*ft_tilda_rubbish_dir(char *s, char c, char *env_value, size_t flag)
{
	char	*start;
	char	*line;
	char	*tmp;

	start = NULL;
	tmp = ft_strchr(s, '$');
	if (flag == 0)
	{
		start = ft_strndup(s + 1, tmp - s - 1);
		line = ft_strjoin(start, env_value);
		ft_strdel(&start);
	}
	else
	{
		start = ft_strndup(s, tmp - s);
		if (c == '\0')
			line = ft_strjoin(start, env_value);
		else
			line = ft_strdup(start);
		ft_strdel(&start);
	}
	return (line);
}

char	*ft_tilda_rubbish(char *s, char *tmp, size_t flag)
{
	if (flag == 1)
	{
		if (*(tmp + 1) != '\0')
			return (ft_strdup("~"));
		else
			return (ft_strdup(s));
	}
	if (*(tmp + 1) == '\0')
		return (ft_strdup(s));
	return (ft_strndup(s + 1, tmp - s - 1));
}

char	*tilda_slash(char **res_str, char *s, t_dict *envs)
{
	char	*tmp;

	tmp = ft_only_current_dir(envs, s);
	*res_str = ft_strjoin(tmp, s + 1);
	ft_strdel(&tmp);
	return (*res_str);
}
