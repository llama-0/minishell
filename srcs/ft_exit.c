#include "minishell.h"

void	ft_exit(char **input, t_dict *envs)
{
	extern char	**environ;

	if (ft_strcmp(input[0], "exit\n"))
	{
		dict_clear(&envs);
		ft_free_char_arr(&environ);
		ft_free_char_arr(&input);
		exit(0);
	}
	else
		ft_putstr_base("exit command not clean\n", 2);
}
