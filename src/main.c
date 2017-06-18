/*
** main.c for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:27:44 2017 benoit pingris
** Last update Sun Jun 18 00:52:53 2017 benoit pingris
*/

#include <unistd.h>
#include "useful.h"
#include "fasta.h"
#include "macro.h"

int	main(const int ac, const char **av)
{
  if (ac != 2)
    return (putstr(INV_CMD, ERROR, STDERR_FILENO));
  if (fasta_tools(av) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
