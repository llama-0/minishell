/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_true_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:16:43 by koparker          #+#    #+#             */
/*   Updated: 2019/10/12 18:22:24 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_true_strtrim(char const *s)
{
	size_t	head;
	size_t	end;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	head = i;
	i = len - 1;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		i--;
		j++;
	}
	end = j;
	return (ft_strndup(s + head, len - head - end));
}
