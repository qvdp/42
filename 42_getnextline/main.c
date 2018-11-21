#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

int   main(void)
{
  char  *line;
  int   fd;

  fd = open("txt", O_RDONLY);
  get_next_line(fd, &line);
  printf("%s\n", line);
  get_next_line(fd, &line);
  printf("%s\n", line);
  close(fd);
  return(0);
}
