/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:39:37 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 16:39:56 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	key_present(t_dict **head, char *key)
{
	t_dict	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

size_t	value_present(t_dict **head, char *value)
{
	t_dict	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->value, value) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_dict	*get_dict_elem(t_dict **head, char *key)
{
	t_dict	*tmp;

	if (!head || !(*head) || !key)
		return (NULL);
	tmp = *head;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, key) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
