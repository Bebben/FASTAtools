/*
** k_mers.c for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 11:34:05 2017 benoit pingris
** Last update Sun Jun 18 11:35:46 2017 benoit pingris
*/

#include "macro.h"
#include "useful.h"

int	k_mers(const char **av, char **tab)
{
  if (!av[2])
    return (ERROR);
  showtab(tab);
  return (SUCCESS);
}
