/*
** epur_str.c for fasta in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 09:43:06 2017 benoit pingris
** Last update Tue Jun 20 10:09:31 2017 benoit pingris
*/

#include <string.h>
#include <stdlib.h>

char	*indent_spaces(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      ++i;
    }
  return (str);
}

char	*epur_str(char *str)
{
  int	i;
  int	h;
  char	*epured;

  h = 0;
  i = 0;
  str = indent_spaces(str);
  if ((epured = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  epured[0] = '\0';
  while (str[i] == ' ')
    ++i;
  while (str[i])
    {
      if (str[i] == ' ')
	epured[h++] = ' ';
      while (str[i] == ' ')
	++i;
      if (str[i] != '\0')
	epured[h++] = str[i++];
    }
  if (h > 0 && epured[h - 1] == ' ')
    epured[h - 1] = '\0';
  return (epured);
}
