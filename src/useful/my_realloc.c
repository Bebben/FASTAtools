/*
** my_realloc.c for fastatools in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 19 14:56:51 2017 benoit pingris
** Last update Tue Jun 20 13:10:38 2017 benoit pingris
*/

#include <stdlib.h>
#include "useful.h"

char	**realloc_tab(char **tab, int size)
{
  char	**cpy;
  int	i;
  int	len;

  len = tab_len(tab);
  if (!(cpy = malloc(sizeof(char *) * (len + size))))
    return (NULL);
  while (tab[i])
    {
      cpy[i] = tab[i];
      ++i;
    }
  cpy[i] = NULL;
  free(tab);
  return (cpy);
}
