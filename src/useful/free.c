/*
** free.c for fasta in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 00:17:16 2017 benoit pingris
** Last update Mon Jun 19 11:08:00 2017 benoit pingris
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}
