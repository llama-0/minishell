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
