/*
** mallocat.c for fasta in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 19 10:54:11 2017 benoit pingris
** Last update Mon Jun 19 16:00:23 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>

char	*mallocat(char *s1, const char *s2)
{
  int	i;
  int	j;
  char	*new;

  if (!s1)
    i = strlen(s2);
  else
    i = strlen(s1) + strlen(s2);
  j = 0;
  if (!(new = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (s1 && s1[i])
    {
      new[i] = s1[i];
      ++i;
    }
  while (s2[j])
    new[i++] = s2[j++];
  new[i] = '\0';
  free(s1);
  return (new);
}

char	*mallocncat(char *s1, char *s2, int n)
{
  int	i;
  int	j;
  char	*new;

  if (!s1)
    i = strlen(s2);
  else
    i = strlen(s1) + strlen(s2);
  j = 0;
  if (!(new = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (s1 && s1[i])
    {
      new[i] = s1[i];
      ++i;
    }
  while (s2[j] && j < n)
    new[i++] = s2[j++];
  new[i] = '\0';
  free(s1);
  return (new);
}
