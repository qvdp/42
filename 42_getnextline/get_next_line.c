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
  if (temp_size < 0)
    return (-1);
  return (temp_size);
}

h_list  *ft_build_elem(char **string, int fd)
{
  char    *temp_string;
  h_list  *element;

  temp_string = *string;
  if (temp_string)
  {
  	if ((element = (h_list*)malloc(sizeof(h_list))))
  	{
      if ((element->line = (char*)malloc(sizeof(*string) * ft_strlen(temp_string))))
      {
        ft_strcpy(element->line, temp_string);
        element->fd = fd;
  	    element->next = NULL;
        return (element);
       }
       free(element);
    }
  }
  return (NULL);
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
    if (pos > 0)
    {
      *line = ft_strsub(temp_string, 0, pos);
      (*element)->line = ft_strsub(temp_string, pos + 1, ft_strlen(temp_string) - pos);
      return (1);
    }
  }
  return (0);
}

int get_next_line(const int fd, char **line)
{
  static h_list *list;
  int size;
  h_list        *temp_list;
  char          *string;

  // Check Error
  if (fd < 0 || !line)
    return (-1);
  if (!list)
    list = NULL;

  // Check fd  & init of string
  temp_list = list;
  while (temp_list && temp_list->next && fd != temp_list->fd)
    temp_list = temp_list->next;
  if (temp_list && fd == temp_list->fd && temp_list->line)
  {
    if (!(string = ft_strdup((temp_list)->line)))
      return (0);
  }
  else
  {
    temp_list = list;
    if (!(string = ft_strnew(0)))
      return (0);
  }

  // Init reading
  if ((size = ft_readfd(fd, &string)) == -1)
    return (-1);
  else if (size == 0 && temp_list && (temp_list->line == NULL || temp_list->line[0] == '\0'))
    return (0);

  // Build new element
  if ((temp_list = ft_build_elem(&string, fd)))
  {
  		temp_list->next = list;
  		list = temp_list;
  }

  // Reading the line
  ft_read_line(&list, line);
  return (1);
}
