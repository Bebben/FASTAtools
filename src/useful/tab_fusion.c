/*
** tab_fusion.c for fasta in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 15:05:05 2017 benoit pingris
** Last update Tue Jun 20 15:44:14 2017 benoit pingris
*/

#include <string.h>
#include <stdlib.h>
#include "useful.h"

char	**tab_fusion(char **tab1, char **tab2)
{
  char	**new;
  int	i;
  int	j;

  if (!tab1 || !tab2)
    return (NULL);
  i = tab_len(tab1) + tab_len(tab2);
  if (!(new = malloc(sizeof(char *) * (i + 1))))
    return (NULL);
  i = 0;
  j = 0;
  while (tab1[i])
    {
      if (!(new[i] = strdup(tab1[i])))
	return (NULL);
      ++i;
    }
  while (tab2[j])
    if (!(new[i++] = strdup(tab2[j++])))
      return (NULL);
  new[i] = NULL;
  return (new);
}
