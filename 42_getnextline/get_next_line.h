#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft/libft.h"

typedef struct		g_list
{
	char			*line;
	int			is_ridden;
  int   fd;
	struct g_list	*next;
}					h_list;

int get_next_line(const int fd, char **line);

#endif
