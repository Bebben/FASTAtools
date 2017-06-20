/*
** format.c for fasta in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:54:13 2017 benoit pingris
** Last update Tue Jun 20 09:42:54 2017 benoit pingris
*/

#include <string.h>
#include <stdlib.h>
#include "macro.h"

int	good_char(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] != 'A' && s[i] != 'T' && s[i] !='C' && s[i] != 'G')
	return (FAILURE);
      ++i;
    }
  return (SUCCESS);
}

char	*uppercase(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] >= 'a' && s[i] <= 'z')
	s[i] = s[i] - 32;
      ++i;
    }
  return (s);
}

static int	check_char(char a)
{
  return (a == 'A' || a == 'T' || a == 'C' || a == 'G' || a == 'N');
}

char	*epur_dna(char *s)
{
  int	i;
  int	h;
  char	*epured;

  h = 0;
  i = 0;
  if (!s || !(epured = malloc(sizeof(char) * (strlen(s) + 1))))
    return (NULL);
  while (s[i])
    {
      if (!check_char(s[i]))
	++i;
      else
	epured[h++] = s[i++];
    }
  if (h > 0 && !check_char(s[i - 1]))
    epured[h - 1] = '\0';
  else
    epured[h] = '\0';
  free(s);
  return (epured);
}
