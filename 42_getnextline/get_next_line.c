#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_readfd(const int fd, char **string)
{
  int   temp_size;
  char  *tmp;
  char  buff[BUFF_SIZE + 1];

  while ((temp_size = read(fd, buff, BUFF_SIZE)) > 0)
  {
    buff[temp_size] = '\0';
    tmp = ft_strjoin(*string, buff);
		free(*string);
    *string = tmp;
    if (ft_strchr(*string, '\n'))
      break;
  }
  return (temp_size);
}

void  *ft_build_elem(h_list **alist, char **string, const int *fd)
{
  h_list  *element;

  if (*string)
  {
  	if ((element = (h_list*)malloc(sizeof(h_list))))
  	{
      if ((element->line = (char*)malloc(sizeof(*string) * ft_strlen(*string))))
      {
        ft_strcpy(element->line, *string);
        element->fd = *fd;
  	    element->next = *alist;
        *alist = element;
      }
      else
        free(element);
    }
    free(*string);
  }
  return (0);
}

int  ft_read_line(h_list **element, char **line)
{
  int  pos;
  char    *temp_string;

  pos = 0;
  temp_string = (*element)->line;
  if (temp_string)
  {
    while (temp_string[pos] != '\0' && temp_string[pos] != '\n')
      pos++;
    *line = ft_strsub(temp_string, 0, pos);
    //free((*element)->line);
    (*element)->line = ft_strsub(temp_string, pos + 1, ft_strlen(temp_string) - pos);
  }
  return (1);
}

int get_next_line(const int fd, char **line)
{
  static h_list *list;
  int size;
  h_list        *temp_list;
  char          *string;

  if (fd < 0 || !line)
    return (-1);
  temp_list = list;
  while (temp_list && temp_list->next && fd != temp_list->fd)
    temp_list = temp_list->next;
  if (temp_list && fd == temp_list->fd && temp_list->line)
    string = ft_strdup(temp_list->line);
  else
  {
    temp_list = list;
    if (!(string = ft_strdup("")))
      return (-1);
  }

  if ((size = ft_readfd(fd, &string)) == -1)
    return (-1);
  else if (size == 0 && (!string || string[0] == '\0'))
    return (0);
  // TO DO - Verifier que je ne construit pas un maillon a chaque appel et que
  // je réutilise bien un maillon existant
  ft_build_elem(&list, &string, &fd);
  return (ft_read_line(&list, line));
}
