/*
** get_opt.c for fasta in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sun Jun 18 00:58:00 2017 benoit pingris
** Last update Tue Jun 20 10:01:42 2017 benoit pingris
*/

#include <unistd.h>
#include <stdlib.h>
#include "fasta.h"
#include "useful.h"
#include "macro.h"

static int	(*opt_fasta[8])(const char **av, char **tab) =
{
  show_dna,
  show_rna,
  reverse,
  k_mers,
  sequence,
  amino_acids,
  dna_align
};

int	get_opt(const char **av, char **tab)
{
  int	i;

  i = atoi(av[1]);
  if ((opt_fasta[i - 1](av, tab)) == ERROR)
    return (putstr(INV_OPT, ERROR, STDERR_FILENO));
  return (SUCCESS);
}

