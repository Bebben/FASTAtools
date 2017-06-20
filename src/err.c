/*
** err.c for faastatools in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 09:57:24 2017 benoit pingris
** Last update Tue Jun 20 13:21:34 2017 benoit pingris
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "useful.h"

int		err(const char **tab)
{
  struct stat	st;
  int		i;

  if (fstat(STDIN_FILENO, &st) == -FAILURE)
    return (putstr(INV_FILE, ERROR, STDERR_FILENO));
  if (st.st_size == 0)
    return (putstr(INV_OPT, ERROR, STDERR_FILENO));
  if (!tab[1])
    return (putstr(INV_OPT, ERROR, STDERR_FILENO));
  i = atoi(tab[1]);
  if (i < 1 || i > 7 || str_isnum(tab[1]) == FAILURE)
    return (putstr(INV_OPT, ERROR, STDERR_FILENO));
  return (SUCCESS);
}
