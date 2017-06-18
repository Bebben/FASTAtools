/*
** format.c for fasta in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:54:13 2017 benoit pingris
** Last update Sun Jun 18 00:18:58 2017 benoit pingris
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

char	*epur_str(char *s)
{
  int	i;
  int	h;
  char	*epured;

  h = 0;
  i = 0;
  if (!s || !(epured = malloc(sizeof(char) * (strlen(s) + 1))))
    return (NULL);
  while (s[i] == ' ' || s[i] == '\t')
    ++i;
  while (s[i])
    {
      while (s[i] == ' ' || s[i] == '\t')
	++i;
      if (s[i])
	epured[h++] = s[i++];
    }
  if (h > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
    epured[h - 1] = '\0';
  else
    epured[h] = '\0';
  free(s);
  return (epured);
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
  while (!check_char(s[i]))
    ++i;
  while (s[i])
    {
      while (!check_char(s[i]))
	++i;
      if (s[i])
	epured[h++] = s[i++];
    }
  if (h > 0 && !check_char(s[i - 1]))
    epured[h - 1] = '\0';
  else
    epured[h] = '\0';
  free(s);
  return (epured);
}
