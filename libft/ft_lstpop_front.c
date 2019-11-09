/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koparker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:02:58 by koparker          #+#    #+#             */
/*   Updated: 2019/10/21 18:50:10 by koparker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstpop_front(t_list **alst)
{
	t_list	*tmp;
	void	*popped;

	if (!(*alst)->content)
		return (NULL);
	tmp = *alst;
	*alst = (*alst)->next;
	popped = tmp->content;
	free(tmp);
	tmp = NULL;
	return (popped);
}
