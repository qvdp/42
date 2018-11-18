#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	if (!(temp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(temp->content = (void*)malloc(sizeof(void) * content_size)))
			return (NULL);
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	else
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	temp->next = NULL;
	return (temp);
}
