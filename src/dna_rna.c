/*
** ptr_fc.c for fasta in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 01:04:13 2017 benoit pingris
** Last update Mon Jun 19 19:44:49 2017 benoit pingris
*/

#include <unistd.h>
#include "useful.h"
#include "macro.h"

int	show_dna(const char **av, char **tab)
{
  if (av[2])
    return (ERROR);
  showtab(tab);
  return (SUCCESS);
}

int	show_rna(const char **av, char **tab)
{
  int	i;
  int	j;

  i = 0;
  if (av[2])
    return (ERROR);
  while (tab[i])
    {
      j = 0;
      if (tab[i][0] != '>')
	while (tab[i][j])
	  {
	    if (tab[i][j] == 'T')
	      tab[i][j] = 'U';
	    ++j;
	  }
      ++i;
    }
  showtab(tab);
  return (SUCCESS);
}

int	dna_align(const char **av, char **tab)
{
  (void)av;
  showtab(tab);
  return (SUCCESS);
}

