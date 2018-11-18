#include "libft.h"
#include <stdlib.h>

void  ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
  if (*alst)
  {
    (*del)((*alst)->content, (*alst)->content_size);
    ft_memdel((void**)alst);
    *alst = NULL;
  }
}
