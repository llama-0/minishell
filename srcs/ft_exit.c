/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:49:49 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 16:48:23 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
