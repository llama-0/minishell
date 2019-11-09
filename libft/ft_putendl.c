/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <kfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:44:08 by koparker          #+#    #+#             */
/*   Updated: 2019/05/28 15:42:50 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** flag == 2 -- '\n' then usual output
** flag == 0 -- usual output
** flag != 0 -- usual output ':' '\n' (for ls error printing)
*/

void	ft_putendl(char const *s, int flag)
{
	if (flag == 2)
		ft_putchar_base('\n', 1);
	ft_putstr_base(s, 1);
	if (flag != 0)
		ft_putchar_base(':', 1);
	ft_putchar_base('\n', 1);
}
