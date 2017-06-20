/*
** fasta.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:31:26 2017 benoit pingris
** Last update Tue Jun 20 15:13:23 2017 benoit pingris
*/

#include <sys/stat.h>
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

char		**my_malloc(char **tab)
{
  int		i;

  if (!(tab = malloc(sizeof(char *) * (MEM_SIZE * 4))))
    return (NULL);
  i = 0;
  while (i < MEM_SIZE * 3)
    tab[i++] = NULL;
  return (tab);
}

static char	**get_fasta(char **tab, int i, char *s)
{
  if (!(tab = my_malloc(tab)))
    return (NULL);
  while ((s = get_next_line(STDIN_FILENO)))
    {
      if (s[0] && s[0] != '>' && strlen(s) != 0)
	{
	  if ((s = format_str(s)) == NULL)
	    return (NULL);
	  if (strlen(s) != 0 && !(tab[i] = mallocat(tab[i], s)))
	    return (NULL);
	  free(s);
	}
      else if (strlen(s) != 0)
	{
	  if (tab[i] != NULL)
	    ++i;
	  tab[i] = s;
	  ++i;
	}
    }
  if (tab[i] != NULL)
    ++i;
  tab[i] = NULL;
  return (tab);
}

int	fasta_tools(const char **av)
{
  char	**tab;

  tab = NULL;
  if (err(av) == ERROR)
    return (ERROR);
  if (!(tab = get_fasta(tab, 0, NULL)))
    return (putstr(ERR_MEM, ERROR, STDERR_FILENO));
  if (get_opt(av, tab) == ERROR)
    return (ERROR);
  free_tab(tab);
  return (SUCCESS);
}
