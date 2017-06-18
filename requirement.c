/*
** requirement.c for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:11:26 2017 benoit pingris
** Last update Sat Jun 17 21:25:21 2017 benoit pingris
*/

char	*my_strcapitalize_synthesis(char *str)
{
  int	i;

  i = 0;
  if (str[i] >= 'a' && str[i] <= 'z')
    str[i] = str[i] - 32;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z' &&
	  !((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
	    (str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
	    (str[i - 1] >= '0' && str[i - 1] <= '9')))
	str[i] = str[i] - 32;
      else if (str[i] >= 'A' && str[i] <= 'Z' &&
	       ((str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
		(str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
		(str[i - 1] >= '0' && str[i - 1] <= '9')))
	str[i] = str[i] + 32;
      ++i;
    }
  return (str);
}
