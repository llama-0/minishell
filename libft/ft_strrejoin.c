/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:57 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 18:50:39 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char const *s1, char const *s2, int num_to_free)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (num_to_free & 1)
		ft_memdel((void **)&s1);
	if (num_to_free & 2)
		ft_memdel((void **)&s2);
	return (res);
}
