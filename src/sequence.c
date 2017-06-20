/*
** sequence.c for fasta in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 19 15:10:40 2017 benoit pingris
** Last update Tue Jun 20 15:44:27 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "useful.h"

static int	check_size(char *s)
{
  if (strlen(s) >= 3)
    return (SUCCESS);
  return (FAILURE);
}

static int	check_end(char *s)
{
  if (strncmp(s, "TAA", 3) == SAME ||
      strncmp(s, "TAG", 3) == SAME ||
      strncmp(s, "TGA", 3) == SAME)
    return (SUCCESS);
  return (FAILURE);
}

static char	**find_sequence(char *s, char **tab, int *j)
{
  char		*cpy;
  char		*tmp;
  int		i;

  i = 0;
  if (!(cpy = strstr(s, "ATG")))
    return (tab);
  tmp = NULL;
  while (check_size(&cpy[i]) == SUCCESS)
    {
      if (check_end(&cpy[i]) == SUCCESS)
	{
	  if (!(tab[*j] = strdup(tmp)))
	    return (NULL);
	  tab[++(*j)] = NULL;
	  free(tmp);
	  break;
	}
      tmp = mallocncat(tmp, &cpy[i], 3);
      i += 3;
    }
  find_sequence(&cpy[2], tab, j);
  return (tab);
}

char	**get_sequence(char **tab)
{
  char	**seq;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!(seq = malloc(sizeof(char *) * (MEM_SIZE * 2))))
    return (NULL);
  while (tab[i])
    {
      if (tab[i][0] != '>')
	if (!(seq = find_sequence(tab[i], seq, &j)))
	  return (NULL);
      ++i;
    }
  return (seq);
}

int	sequence(const char **av, char **tab)
{
  char	**seq;
  char	**rev;

  rev = NULL;
  if (!(rev = tab_fusion(tab, get_reverse(tab))))
    return (ERROR);
  if (av[2] || (!(seq = get_sequence(rev))))
    return (ERROR);
  sort_tab(seq);
  showtab(seq);
  free_tab(seq);
  free_tab(rev);
  return (SUCCESS);
}
