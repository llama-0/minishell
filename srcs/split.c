/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:23:04 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 17:01:33 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_quoted(char *tmp, size_t *i, char **s, char c)
{
	tmp[(*i)++] = **s;
	(*s)++;
	while (**s != '\0' && **s != c)
	{
		tmp[(*i)++] = **s;
		(*s)++;
	}
	if (**s != '\0')
	{
		tmp[(*i)++] = **s;
		(*s)++;
	}
}

static void	ft_close_str(char *tmp, size_t *i, char **s)
{
	while (**s != '\0' && (**s == ' ' || **s == '\t'))
		(*s)++;
	tmp[(*i)++] = '\n';
}

char		*base_split(char *s)
{
	char	*tmp;
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s) * LEN_BOOST;
	tmp = (char *)ft_memalloc(len);
	while (*s != '\0')
	{
		while (*s != '\0' && *s != ' ' && *s != '\t')
		{
			if (*s != '\0' && *s == '"')
				ft_quoted(tmp, &i, &s, '"');
			else if (*s != '\0' && *s == '\'')
				ft_quoted(tmp, &i, &s, '\'');
			else if (*s != '\0')
				tmp[i++] = *(s++);
		}
		ft_close_str(tmp, &i, &s);
	}
	res = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (res);
}
