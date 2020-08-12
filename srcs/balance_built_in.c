#include "minishell.h"

/*
** This func decides what built-in to call (ex., 'echo')
*/

size_t	ft_built_in(char **input, t_dict *envs, t_dict **bins)
{
	char	*instruction;

	instruction = input[0];
	if (!ft_strcmp(instruction, "echo"))
		return (ft_echo(input));
	else if (!ft_strcmp(instruction, "cd"))
		return (ft_cd(input, envs));
	else if (!ft_strcmp(instruction, "setenv"))
		return (ft_setenv(input, envs, bins));
	else if (!ft_strcmp(instruction, "unsetenv"))
		return (ft_unsetenv(input, envs, bins));
	else if (!ft_strcmp(instruction, "env"))
		return (ft_env(input, envs));
	else if (!(ft_strcmp(instruction, "exit")))
		ft_exit(input, envs);
	return (1);
}
