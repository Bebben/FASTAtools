/*
** is_num.c for fasta in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 19 23:49:03 2017 benoit pingris
** Last update Mon Jun 19 23:51:18 2017 benoit pingris
*/

#include "macro.h"

int	str_isnum(const char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (!(s[i] >= '0' && s[i] <= '9'))
	return (FAILURE);
      ++i;
    }
  return (SUCCESS);
}
