#include "minishell.h"

t_dict	*new_bin(char *key, char *value)
{
	t_dict	*elem;

	if (!(elem = (t_dict *)malloc(sizeof(t_dict))))
		return (NULL);
	elem->key = ft_strdup(key);
	elem->value = ft_strdup(value);
	elem->next = NULL;
	return (elem);
}

t_dict	*new_pair(char *s, int need_to_free)
{
	t_dict	*elem;
	char	*tmp;

	if (!(elem = (t_dict *)malloc(sizeof(t_dict))))
	{
		if (need_to_free)
			ft_strdel(&s);
		return (NULL);
	}
	if ((tmp = ft_strchr(s, '=')) != NULL)
	{
		elem->key = ft_strndup(s, tmp - s);
		if (*(tmp + 1) != '\0')
			elem->value = ft_strsub(s, tmp - s + 1,
					ft_strlen(s) - ft_strlen(elem->key) - 1);
		else
			elem->value = ft_strdup("");
	}
	elem->next = NULL;
	tmp = NULL;
	if (need_to_free)
		ft_strdel(&s);
	return (elem);
}

void	push_back_pair(t_dict **head, t_dict *elem)
{
	t_dict	*tmp;

	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

void	remove_pair(t_dict **head, char *key)
{
	t_dict	*tmp;
	t_dict	*prev;

	tmp = *head;
	while (tmp != NULL)
	{
		while (tmp != NULL && tmp->key != key)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp != NULL)
		{
			prev->next = tmp->next;
			ft_strdel(&(tmp->key));
			ft_strdel(&(tmp->value));
			free(tmp);
			tmp = prev->next;
			return ;
		}
	}
}

void	dict_clear(t_dict **head)
{
	t_dict	*tmp;

	tmp = NULL;
	if (*head == NULL)
		return ;
	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_strdel(&(tmp->key));
		ft_strdel(&(tmp->value));
		free(tmp);
		tmp = NULL;
	}
	*head = NULL;
}
