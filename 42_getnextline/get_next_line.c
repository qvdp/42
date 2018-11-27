#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_readfd(int fd, char **string)
{
  size_t   temp_size;
  size_t   size;
  char  *temp_string;
  char  buf[BUFF_SIZE + 1];

  *string = 0;
  size = 0;
  while ((temp_size = read(fd, buf, BUFF_SIZE)) > 0)
  {
    buf[temp_size] = '\0';
    size += temp_size;
    temp_string = *string;
    if (!(*string = (char*)malloc(sizeof(*string) * size + 1)))
      return (-1);
    if (size > BUFF_SIZE)
      ft_strcpy(*string, temp_string);
    ft_strcat(*string, buf);
    free(temp_string);
    if (ft_strchr(*string, '\n'))
      break;
  }
  if(temp_size < 0)
  {
    free(buf);
    return (-1);
  }
  return (0);
}

h_list	*ft_create_elem(char **line, const int fd, size_t line_length)
{
	h_list *tmp;

	if ((tmp = (h_list*)malloc(sizeof(h_list))))
	{
    // printf("|-Creating a new element with this line\n");
    if ((tmp->line = (char*)malloc(sizeof(*line) * line_length)))
    {
      ft_strcpy(tmp->line, *line);
      tmp->is_read = 0;
      tmp->fd = fd;
	    tmp->next = NULL;
      return (tmp);
     }
     free(tmp);
  }
	return (NULL);
}

void	ft_list_push_back(h_list **begin_list, h_list **new_list)
{
	h_list *last;

  if (new_list)
  {
  	if (!*begin_list)
    {
      // printf("|-No existing list\n");
      *begin_list = *new_list;
    }
    else
    {
      last = *begin_list;
    	while (last->next)
      {
        // printf("|-...loop on next element\n");
        last = last->next;
      }
      last->next = *new_list;
    }
    // printf("|-New element pushed & set as unread");
  }
}

h_list  *ft_build_elem(char **string, const int *fd)
{
  int  pos;
  char    *temp_string;
  h_list  *new_list;

  // printf("\n🏁 STEP 2 - Trying to create new elem aslong there is a string\n");
  pos = 0;
  temp_string = *string;
  if (temp_string)
  {
    while (temp_string[pos] != '\0' && temp_string[pos] != '\n')
      pos++;
    if (pos > 0)
    {
      // printf("|-A Line finish at %d in string\n", pos);
      temp_string = ft_strsub(*string, 0, pos);
      // printf("|-Line is %s\n", temp_string);
      *string = ft_strsub(*string, pos + 1, ft_strlen(*string) - pos);
      // printf("|-New string \n```\n%s\n```\n", *string);
      if ((new_list = ft_create_elem(&temp_string, *fd, pos)))
      {
        free(temp_string);
        return (new_list);
      }
    }
  }
  return (NULL);
}

int get_next_line(const int fd, char **line)
{
  static h_list *list;
  h_list        *temp_list;
  char          *string;

  // printf("GNL started 🚀\n");
  // TO DO - in this fd.
  // printf("\n🏁 STEP O - Checking if unread sentence had been set in same fd\n");
  if (!list)
    list = NULL;
  else
  {
    // printf("|-A list exist\n");
    while (list->is_read == 1 && list->next)
    {
      // printf("|-An element has been read and needs to be free\n");
      temp_list = list->next;
      free(list->line);
      free(list);
      list = temp_list;
    }
    // printf("|-Is this element read ?\n");
    if (list->is_read == 0)
    {
      list->is_read = 1;
      *line = list->line;
      return (1);
    }
    free(list->line);
    free(list);
    list = NULL;
  }
  // printf("\n🏁 STEP 1 - Reading the fd\n");
  if (!(ft_readfd(fd, &string) == 0))
  {
    *line = NULL;
    free(list);
    free(string);
    return (-1);
  }

  // TO DO - For the first occ, verify if the last set part contains a /n or no to finish the line or begin a new one
  while ((temp_list = ft_build_elem(&string, &fd)))
  {
    // printf("\n🏁 STEP 3 - Pushing new elem\n");
    ft_list_push_back(&list, &temp_list);
  }
  free(string);
  if (list && list->is_read == 0)
  {
    list->is_read = 1;
    *line = list->line;
    return (1);
  }
  return (0);
}
