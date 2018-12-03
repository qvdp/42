#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
  int fd;
  char *line;

  fd = open("txt", O_RDONLY);
  while (get_next_line(fd, &line) > 0)
    ft_putendl(line);
  close(fd);
  return (0);
}
