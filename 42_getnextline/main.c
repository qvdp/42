#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
  int fd;
  int ret;
  char *line;
  
  fd = open("./test/", O_RDONLY);
  while ((ret = get_next_line(fd, &line)) > 0 && line != NULL)
  {
    ft_putendl(line);
    ft_strdel(&line);
  }
  ft_putnbr(ret);
  ft_putstr(" | ");
  ft_putendl(line);
  ft_strdel(&line);
  close(fd);
  return (0);
}
