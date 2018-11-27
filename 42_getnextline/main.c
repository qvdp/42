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
  int   fd2;
  int   fd3;

  line = NULL;
  printf("************************\n");
  printf("TEST 1 - Error fd\n");
  printf("************************\n\n");
  printf("%d", get_next_line(-1, &line));
  printf("%s\n", line);

  printf("\n************************\n");
  printf("TEST 2 - Closed fd\n");
  printf("************************\n\n");
  fd = open("txt~", O_RDONLY);
  close(fd);
  printf("%d", get_next_line(fd, &line));
  printf("%s\n", line);

  fd2 = 0;
  fd2 = open("txt", O_RDONLY);
  printf("\n************************\n");
  printf("TEST 3 - fd unfinished line\n");
  printf("************************\n\n");
  printf("%d", get_next_line(fd2, &line));
  printf("%s\n", line);
  close(fd2);

  fd3 = open("txt2", O_RDONLY);
  printf("\n************************\n");
  printf("TEST 4 - fd 1nd line\n");
  printf("************************\n\n");
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);

  printf("\n************************\n");
  printf("TEST 5 - fd 2nd line\n");
  printf("************************\n\n");
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);

  printf("\n************************\n");
  printf("TEST 6 - Finished fd\n");
  printf("************************\n\n");
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);
  printf("%d", get_next_line(fd3, &line));
  printf("%s\n", line);
  close(fd3);

  return(0);
}
