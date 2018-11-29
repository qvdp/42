#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_readfd(const int fd, char **string)
{
  int   temp_size;
  char  *tmp;
  char  buff[BUFF_SIZE + 1];

  // printf("|- Starting to read\n");
  while ((temp_size = read(fd, buff, BUFF_SIZE)) > 0)
  {
    buff[temp_size] = '\0';
    tmp = ft_strjoin(*string, buff);
		free(*string);
    *string = tmp;
    if (ft_strchr(*string, '\n'))
      break;
  }
  // printf("%s\n", *string);
  // printf("temp_size %d\n", temp_size);
  // printf("|- Read finished\n");
  if (temp_size < 0)
  {
    // printf("|- Error founded \n");
    return (-1);
  }
  return (temp_size);
}

h_list  *ft_build_elem(char **string, const int *fd)
{
  char    *temp_string;
  h_list  *element;

  temp_string = *string;
  if (temp_string)
  {
  	if ((element = (h_list*)malloc(sizeof(h_list))))
  	{
      // printf("|-Creating a new element with this line & fd\n");
      if ((element->line = (char*)malloc(sizeof(*string) * ft_strlen(temp_string))))
      {
        ft_strcpy(element->line, temp_string);
        element->fd = *fd;
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
      // printf("|-A Line finish at %d in string\n", pos);
      *line = ft_strsub(temp_string, 0, pos);
      // printf("|-Line is %s\n", *line);
      (*element)->line = ft_strsub(temp_string, pos + 1, ft_strlen(temp_string) - pos);
      // printf("|-New string \n```\n%s\n```\n", (*element)->line);
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

  // printf("GNL started 🚀\n");

  // Check Error
  // printf("\n🏁 STEP O - Checking error\n");
  if (fd < 0 || !line)
    return (-1);
  if (!list)
    list = NULL;
  // Check fd  & init of string
  temp_list = list;
  // printf("\n🏁 STEP 1 - Init the temp string (depend on fd)\n");
  while (temp_list && temp_list->next && fd != temp_list->fd)
    temp_list = temp_list->next;
  if (temp_list && fd == temp_list->fd && temp_list->line)
  {
    // printf("|- Trying to read same fd\n");
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
  // printf("\n🏁 STEP 2 - Reading the fd\n");
  if ((size = ft_readfd(fd, &string)) == -1)
    return (-1);
  else if (size == 0 && (!string || string[0] == '\0'))
    return (0);

  // Build new element
  // printf("\n🏁 STEP 3 - Trying to create new elem\n");
  if ((temp_list = ft_build_elem(&string, &fd)))
  {
  		temp_list->next = list;
  		list = temp_list;
  }

  // Reading the line
  // printf("\n🏁 STEP 4 - Giving the line\n");
  ft_read_line(&list, line);
  // printf("\nGNL end \n\n");
  return (1);
}
