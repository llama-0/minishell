/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:06:15 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 16:05:27 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**read_input(void)
{
	char	**res;
	char	*tmp;
	char	*line;
	size_t	i;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		exit(0);
	res = ft_strsplit(line, ';');
	i = 0;
	while (res[i] != NULL)
	{
		tmp = res[i];
		res[i] = ft_strtrim(tmp);
		ft_strdel(&tmp);
		i++;
	}
	ft_strdel(&line);
	return (res);
}

static void		execute(char **command, t_dict *envs, t_dict **bins)
{
	t_dict	*elem;
	DIR		*dir;
	size_t	flag;

	flag = 0;
	if (ft_built_in(command, envs, bins) != 0)
	{
		if (is_a_dir(command[0]) == 1)
		{
			dir = opendir(command[0]);
			if (value_present(&envs, command[0]) == 1 || dir != NULL)
			{
				flag = go_to_dir(command, envs);
				if (dir)
					closedir(dir);
			}
		}
		if ((elem = get_dict_elem(bins, command[0])) != NULL)
			ft_from_bins(command, elem->value);
		else if (is_input_rubbish(command, envs, flag) == 0 && flag == 0)
			ft_from_bins(command, command[0]);
	}
}

static void		str_to_commands(char ***input, char *s, t_dict *envs)
{
	char	**tmp;

	*input = ft_strsplit(s, '\n');
	tmp = *input;
	*input = ft_substitute_vars(tmp, envs);
	ft_free_char_arr(&tmp);
}

static size_t	check_first_cmd(char **s)
{
	char	*tmp;

	tmp = *s;
	if (!(*tmp))
		return (1);
	*s = base_split(tmp);
	ft_strdel(&tmp);
	return (0);
}

void			init(t_dict *envs, t_dict **bins)
{
	char	**input_commands;
	char	**input;
	size_t	i;

	while (1)
	{
		ft_putstr_base("$> ", 1);
		input_commands = read_input();
		i = -1;
		while (input_commands[++i] != NULL)
		{
			if (check_first_cmd(&input_commands[i]))
				continue ;
			str_to_commands(&input, input_commands[i], envs);
			if (!input || !input[0])
			{
				ft_free_char_arr(&input);
				continue ;
			}
			execute(input, envs, bins);
			ft_free_char_arr(&input);
		}
		ft_free_char_arr(&input_commands);
	}
}
