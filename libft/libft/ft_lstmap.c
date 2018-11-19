#include "libft.h"

t_list *  ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	if (lst && f)
	{
		while (lst)
		{	
			tmp = (*f)(lst);
			ft_lstadd(&new,tmp);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
