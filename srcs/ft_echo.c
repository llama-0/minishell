/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <koparker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 22:55:26 by koparker          #+#    #+#             */
/*   Updated: 2019/09/07 22:12:19 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
