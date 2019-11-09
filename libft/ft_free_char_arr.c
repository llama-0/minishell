/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:50:07 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/15 20:13:53 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_char_arr(char ***arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
		{
			free((*arr)[i]);
			(*arr)[i] = NULL;
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}
