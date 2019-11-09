/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:33:15 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 18:56:59 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_bins_dict(char *path, t_dict **dict)
{
	DIR				*dir;
	struct dirent	*dp;
	char			*tmp;
	struct stat		st;

	if (!(dir = opendir(path)))
		return ;
	while ((dp = readdir(dir)) != NULL)
	{
		if (path[ft_strlen(path) - 1] != '/')
			tmp = ft_strjoin_chr(path, dp->d_name, '/');
		else
			tmp = ft_strjoin(path, dp->d_name);
		if ((access(tmp, F_OK) == 0 || access(tmp, R_OK) == 0)
				&& stat(tmp, &st) >= 0 && S_ISREG(st.st_mode) > 0)
		{
			if (key_present(dict, dp->d_name) != 1)
				push_back_pair(dict, new_bin(dp->d_name, tmp));
		}
		ft_strdel(&tmp);
	}
	closedir(dir);
}

void		bins_dict(t_dict **dict_bins, t_dict *envs)
{
	char	**bins;
	char	*path;
	size_t	i;

	if (dict_bins && *dict_bins)
		dict_clear(dict_bins);
	if (!(path = ft_path(envs)))
		return ;
	bins = ft_strsplit(path, ':');
	i = 0;
	while (bins[i])
	{
		fill_bins_dict(bins[i], dict_bins);
		i++;
	}
	ft_free_char_arr(&bins);
}

int			main(void)
{
	t_dict		*envs;
	t_dict		*bins;
	char		**envp_new;
	extern char	**environ;
	size_t		i;

	i = 0;
	envs = NULL;
	if (read(0, NULL, 0) == -1)
		return (1);
	while (environ[i] != NULL)
		push_back_pair(&envs, new_pair(environ[i++], 0));
	bins = NULL;
	bins_dict(&bins, envs);
	if (!(envp_new = (char **)malloc(sizeof(char *) *
					(ft_2d_strlen(environ) + 1))))
		exit(1);
	i = -1;
	while (environ[++i] != NULL)
		envp_new[i] = ft_strdup(environ[i]);
	envp_new[i] = NULL;
	environ = envp_new;
	init(envs, &bins);
	return (0);
}
