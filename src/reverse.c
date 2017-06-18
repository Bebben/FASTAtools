/*
** reverse.c for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 11:29:44 2017 benoit pingris
** Last update Sun Jun 18 11:30:10 2017 benoit pingris
*/

#include <string.h>
#include <unistd.h>
#include "macro.h"
#include "useful.h"

void	reverse_tab(char **tab, int i, int j)
{
  while (tab[i])
    {
      j = strlen(tab[i]) - 1;
      if (tab[i][0] != '>')
	{
	  while (j >= 0)
	    {
	      if (tab[i][j] == 'A')
		my_putchar('T');
	      else if (tab[i][j] == 'T')
		my_putchar('A');
	      else if (tab[i][j] == 'C')
		my_putchar('G');
	      else if (tab[i][j] == 'G')
		my_putchar('C');
	      --j;
	    }
	}
      else
	putstr(tab[i], SUCCESS, STDOUT_FILENO);
      my_putchar('\n');
      ++i;
    }
}

int	reverse(const char **av, char **tab)
{
  (void)av;
  reverse_tab(tab, 0, 0);
  return (SUCCESS);
}

