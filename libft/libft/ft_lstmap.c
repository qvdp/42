/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:56:46 by qvan-der          #+#    #+#             */
/*   Updated: 2018/11/19 12:57:22 by qvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (lst && f)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new = NULL;
		while (lst)
		{
			if (new == NULL)
			{
				if (!(tmp = (*f)(lst)))
					return (NULL);
				tmp->next = new;
				new = tmp;
			}
			else
			{
				if (!(tmp = (*f)(lst)))
					return (NULL);
				ft_lstadd(&new, tmp);
			}
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
