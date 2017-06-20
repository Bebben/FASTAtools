/*
** sorting.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 22:11:33 2017 benoit pingris
** Last update Mon Jun 19 11:46:43 2017 benoit pingris
*/

#include <string.h>

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void	sort_tab(char **tab)
{
  char	*s;
  int	times;
  int	i;

  times = tab_len(tab) * tab_len(tab);
  while (times != 0)
    {
      i = 0;
      while (tab[i])
	{
	  if (tab[i + 1] && strcmp(tab[i], tab[i + 1]) > 0)
	    {
	      s = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = s;
	    }
	  ++i;
	}
      --times;
    }
}
