#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int   main()
{
  char  *line;
  int   fd;

  fd = open("test", O_RDONLY);
  while (get_next_line(fd, &line) == 1)
  {
    printf("get next line = %s\n", line);
    free(line);
  }
  /*get_next_line(fd, &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd, &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd, &line);
  printf("get next line = %s\n", line);
  free(line);*/
  close(fd);
  return (0);
}
