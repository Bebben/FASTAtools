/*
** main.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:27:44 2017 benoit pingris
** Last update Tue Jun 20 16:02:40 2017 benoit pingris
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "useful.h"
#include "fasta.h"
#include "macro.h"
#include "gnl.h"

int	disp_help()
{
  char	*s;
  int	fd;

  if ((fd = open(HELP, O_RDONLY)) == -1)
    return (ERROR);
  while ((s = get_next_line(fd)))
    {
      putstr(s, SUCCESS, STDOUT_FILENO);
      putstr("\n", SUCCESS, STDOUT_FILENO);
      free(s);
    }
  close(fd);
  return (SUCCESS);
}

int	main(const int ac, const char **av)
{
  if (ac < 2)
    return (putstr(INV_CMD, ERROR, STDERR_FILENO));
  if (strcmp(av[1], H_FLAG) == SAME)
    return (disp_help());
  if (fasta_tools(av) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
