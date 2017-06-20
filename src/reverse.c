/*
** reverse.c for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 11:29:44 2017 benoit pingris
** Last update Tue Jun 20 15:44:03 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "macro.h"
#include "useful.h"

char	rev_char(char a)
{
  if (a == 'A')
    return ('T');
  else if (a == 'T')
    return ('A');
  else if (a == 'C')
    return ('G');
  else if (a == 'G')
    return ('C');
  else if (a == 'N')
    return ('N');
  else
    return (a);
}

static char	**my_malloc(char **tab, char **new)
{
  int		i;

  i = 0;
  if (!(new = malloc(sizeof(char *) * (tab_len(tab) + 1))))
    return (NULL);
  while (i < tab_len(tab))
    {
      if (!(new[i] = malloc(sizeof(char) * (strlen(tab[i]) + 1))))
	return (NULL);
      ++i;
    }
  new[i] = NULL;
  return (new);
}

char	**get_reverse(char **tab)
{
  char	**new;
  int	i;
  int	j;
  int	h;

  i = 0;
  new = NULL;
  if (!(new = my_malloc(tab, new)))
    return (NULL);
  while (tab[i])
    {
      h = 0;
      j = strlen(tab[i]) - 1;
      if (tab[i][0] != '>')
	while (j >= 0)
	  new[i][h++] = rev_char(tab[i][j--]);
      else
	while (tab[i][h])
	  {
	    new[i][h] = tab[i][h];
	    ++h;
	  }
      new[i++][h] = '\0';
    }
  return (new);
}

int	reverse(const char **av, char **tab)
{
  char	**rev;

  rev = NULL;
  (void)av;
  if (!(rev = get_reverse(tab)))
    return (ERROR);
  showtab(rev);
  return (SUCCESS);
}

