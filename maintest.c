#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int   main()
{
  char  *line;
  int   fd[4];

  /*
  fd[3] = open("test2", O_RDONLY);
  while (get_next_line(fd[3], &line))
  {
	  printf("get next line = %s\n", line);
	  free(line);
  }
  printf("get next line = %s\n", line);
  free(line);
  close(fd[3]);
  */
  
  fd[0] = open("huge_alphabet", O_RDONLY);
  fd[1] = open("test2", O_RDONLY);
  fd[2] = open("test", O_RDONLY);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[1], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[1], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[1], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[1], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[1], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[2], &line);
  printf("get next line = %s\n", line);
  free(line);
  get_next_line(fd[0], &line);
  printf("get next line = %s\n", line);
  free(line);
  close(fd[0]);
  close(fd[1]);
  close(fd[2]);
  
  return (0);
}
