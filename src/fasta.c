/*
** fasta.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:31:26 2017 benoit pingris
** Last update Sun Jun 18 11:36:39 2017 benoit pingris
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"
#include "fasta.h"
#include "macro.h"
#include "useful.h"

static char	*format_str(char *s)
{
  if (s[0] && s[0] != '>')
    {
      s = uppercase(s);
      if (!(s = epur_dna(s)))
	return (NULL);
    }
  return (s);
}

static char	**my_malloc(char **tab)
{
  int		i;

  i = 0;
  tab = malloc(sizeof(char *) * 101);
  while (i < 100)
    {
      tab[i] = malloc(sizeof(char) * 200);
      tab[i][0] = '\0';
      ++i;
    }
  return (tab);
}

static char	**get_fasta(char **tab, int i)
{
  char		*s;

  tab = my_malloc(tab);
  while ((s = epur_str(get_next_line(STDIN_FILENO))))
    {
      if (s[0] && s[0] != '>' && strlen(s) != 0)
	{
	  if ((s = format_str(s)) == NULL)
	    return (NULL);
	  sprintf(tab[i], "%s%s", tab[i], s);
	  free(s);
	}
      else if (strlen(s) != 0)
	{
	  if (i > 0)
	    ++i;
	  tab[i] = s;
	  ++i;
	}
    }
  if (tab[i][0] != '\0')
    ++i;
  tab[i] = NULL;
  return (tab);
}

int	fasta_tools(const char **av)
{
  char	**tab;

  tab = NULL;
  if (!(tab = get_fasta(tab, 0)))
    return (putstr(ERR_MEM, ERROR, STDERR_FILENO));
  if (get_opt(av, tab) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
