#include "minishell.h"

size_t	ft_echo(char **input)
{
	size_t	i;

	i = 1;
	while (input[i] != NULL)
	{
		if (!(ft_strchr(input[i], '$')))
		{
			ft_putstr_base(input[i], 1);
			i++;
			if (input[i] != NULL)
				ft_putchar(' ');
		}
		else
			i++;
	}
	ft_putchar('\n');
	return (0);
}
