/*
** putstr.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:36:27 2017 benoit pingris
** Last update Sun Jun 18 11:32:47 2017 benoit pingris
*/

#include <string.h>
#include <unistd.h>
#include "macro.h"

int	putstr(char *s, int ret, int stream)
{
  write(stream, s, strlen(s));
  return (ret);
}

char	*put_null(char *s, int stream)
{
  write(stream, s, strlen(s));
  return (NULL);
}

int	showtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      putstr(tab[i], SUCCESS, STDOUT_FILENO);
      putstr("\n", SUCCESS, STDOUT_FILENO);
      ++i;
    }
  return (SUCCESS);
}

void	my_putchar(char a)
{
  write(1, &a, 1);
}
