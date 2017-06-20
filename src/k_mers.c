/*
** k_mers.c for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 11:34:05 2017 benoit pingris
** Last update Mon Jun 19 22:19:35 2017 benoit pingris
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "macro.h"
#include "useful.h"

int		get_pos(char **tab, size_t k)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][0] != '>' && k <= strlen(tab[i]))
	return (i);
      ++i;
    }
  return (-FAILURE);
}

static int	check_size(char *s, int k)
{
  if ((int)strlen(s) < k)
    return (FAILURE);
  return (SUCCESS);
}

int		check_double(char *s, int k, char **tab)
{
  int		i;
  char		*tmp;

  if (tab)
    {
      if (!(tmp = strndup(s, k)))
	return (ERROR);
      i = 0;
      while (tab[i])
	{
	  if (strcmp(tab[i], tmp) == 0)
	    {
	      free(tmp);
	      return (FAILURE);
	    }
	  ++i;
	}
      free(tmp);
    }
  return (SUCCESS);
}

char		**get_mers(char *s, int k, char **tab, int *j)
{
  int		i;

  i = 0;
  while (check_size(&s[i], k) == SUCCESS)
    {
      if (check_double(&s[i], k, tab) == SUCCESS)
	{
	  if (!(tab[*j] = strndup(&s[i], k)))
	    return (NULL);
	  tab[++(*j)] = NULL;
	}
      ++i;
    }
  return (tab);
}

int		k_mers(const char **av, char **tab)
{
  size_t	k;
  int		i;
  int		j;
  char		**mers;

  if (av[2] && atoi(av[2]) <= 0)
    return (ERROR);
  if ((i = 0) == 0 && (j = 0) == 0 &&
      (!av[2] || (k = atoi(av[2])) <= 0))
    return (ERROR);
  if (!(mers = malloc(sizeof(char *) * (MEM_SIZE) * 10)))
    return (ERROR);
  mers[j] = NULL;
  while (tab[i])
    {
      if (tab[i][0] != '>' &&
	  !(mers = get_mers(tab[i], k, mers, &j)))
	return (ERROR);
      ++i;
    }
  sort_tab(mers);
  showtab(mers);
  free_tab(mers);
  return (SUCCESS);
}
