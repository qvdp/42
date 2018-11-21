#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t  ft_lenofline(char *s)
{
  size_t  i;

  i = 0;
  while (s[i] != '\0' && s[i] != '\n')
    i++;
  return (i);
}

void	ft_lstaddlist(h_list **alst, h_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void  *ft_build_part(h_list **alst, char *string)
{
  size_t  end;
  char    *temp_string;
  h_list  *temp_list;

  printf("\n------\nBuilding a new part for the chain\n--\n");
  //Builing the line
  end = ft_lenofline(tab);
  temp_string = ft_strsub(tab, 0, end);// end of building
  //Creation du maillon temporaire
  if (!(temp_list = (h_list*)malloc(sizeof(h_list))))
    return (0);
  // Remplissage du maillon
  if (!(temp_list->line = (char*)malloc(sizeof(char) * end + 1)))
    return (0);
  ft_memcpy(temp_list->line, temp_string, end + 1);
  temp_string = NULL;
  free(temp_string);
  temp_list->is_ridden = '0';
  temp_list->fd = fd;
  // Print du contenu du maillon
    printf("[Line. %s]\n", temp_list->line);
    printf("[State. %c]\n", temp_list->is_ridden);
    printf("[Fd. %d]\n", temp_list->fd);
    printf("--\n🏁 Part is ready\n--\n");
  // Ajouter en fin de list plutot qu'au debut
  ft_lstaddlist(&list, temp_list);

  // Rebuild du tab
  tab = ft_strsub(tab, end + 1, ft_strlen(tab) - end);
  printf("Now tab is -|%s|-\n------\n", tab);
}

int get_next_line(const int fd, char **line)
{
  static h_list *list;

  int temp_size;
  int size;
  size_t end;
  char *tab;
  char *temp;
  char buf[BUFF_SIZE + 1];

  printf("GNL Started 🚀\n");
  tab = 0;
  size = 0;

  //Creation de la liste chainée
  if (!list)
  {
    printf("Init the chained list null pointed.\n");
    if (!(list = (h_list*)malloc(sizeof(h_list))))
      return (0);
    list = NULL;
  }

  temp_list = list;
  // Verification de la presence d'un maillon non lu & free des maillons lu
  while (temp_list)
  {
    printf("Verification de l'existence d'un maillon\n");
    if(temp_list->is_ridden == '0')
    {
      printf("Founded : %s\n", temp_list->line);
      *line = temp_list->line;
      temp_list->is_ridden = '1';
      return (0);
    }
    temp_list = temp_list->next;
  }
  printf("Nothing found\n");

  // Read du file descriptor
  printf("\nNo more line to read in the chain, so start reading 👓\n");
  while ((temp_size = read(fd, buf, BUFF_SIZE)) > 0)
  {
    buf[temp_size] = '\0';
    size += temp_size;
    printf("%d | %d\n", temp_size, size);
    temp = tab;
    if (!(tab = (char*)malloc(sizeof(char) * size + 1)))
      return (0);
    if (size > BUFF_SIZE)
      ft_strcpy(tab, temp);
    ft_strcat(tab, buf);
    free(temp);
    if (ft_strchr(tab, '\n'))
      break;
  }
  printf("Reading finished\n");

  // Creation d'un maillon par ligne detectee (verifier si le dernier maillon est une phrase terminee par un /n)
  while (tab)
  {

  }
  free(tab);
  temp_list = list;
  // Reading the chained list
  while (temp_list->next)
    temp_list = temp_list->next;
  *line = temp_list->line;
  temp_list->is_ridden = '1';
  printf("GNL end\n");
  return (0);
}
