/*
** acids.c for fastatools in /home/benoit.pingris/delivery/synthesis/ADM_FASTAtools_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Mon Jun 19 17:10:58 2017 benoit pingris
** Last update Tue Jun 20 16:24:10 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "useful.h"
#include "macro.h"
#include "fasta.h"
#include "ptr.h"

static	t_pointer	ptrf[20] =
  {
    {"GCT-GCC-GCA-GCG", 'A'},
    {"TGT-TGC", 'C'},
    {"GAT-GAC", 'D'},
    {"GAA-GAG", 'E'},
    {"TTT-TTC", 'F'},
    {"GGT-GGC-GGA-GGG", 'G'},
    {"CAT-CAC", 'H'},
    {"ATT-ATC-ATA", 'I'},
    {"AAA-AAG", 'K'},
    {"TTA-TTG-CTT-CTC-CTA-CTG", 'L'},
    {"ATG", 'M'},
    {"AAT-AAC", 'N'},
    {"CCT-CCC-CCA-CCG", 'P'},
    {"CCA-CAG", 'Q'},
    {"AGA-AGG-CGT-CGC-CGA", 'R'},
    {"TCT-TCC-TCA-TCG-AGT-AGC", 'S'},
    {"ACT-ACC-ACA-ACG", 'T'},
    {"GTT-GTC-GTA-GTG", 'V'},
    {"TGG", 'W'},
    {"TAT-TAC", 'Y'}
  };

static int	check_size(char *s)
{
  if (strlen(s) >= 3)
    return (SUCCESS);
  return (FAILURE);
}

char	**transform_char(char **arr, char *s, int *w, int i)
{
  int	v;
  int	k;
  char	*tmp;

  k = 0;
  v = 0;
  while (check_size(&s[k]) == SUCCESS)
    {
      i = 0;
      tmp = strndup(&s[k], 3);
      while (i < SIZE)
	{
	  if (strstr(tmp, "N") && (arr[*w][v++] = 'X') == 'X')
	    break;
	  if (strstr(ptrf[i].codons, tmp) &&
	      (arr[*w][v++] = ptrf[i].letter) == ptrf[i].letter)
	    break;
	  ++i;
	}
      free(tmp);
      k += 3;
    }
  arr[(*w)++][v] = '\0';
  return (arr);
}

void	sort_show_free(char **arr, char **seq)
{
  sort_tab(arr);
  showtab(arr);
  free_tab(arr);
  free_tab(seq);
}

int	amino_acids(const char **av, char **tab)
{
  char	**seq;
  char	**arr;
  char	**rev;
  int	j;
  int	w;

  rev = NULL;
  if (((w = 0) == 0 && (j = 0) == 0 && av[2]) ||
      !(rev = tab_fusion(tab, get_reverse(tab))) ||
      !(seq = get_sequence(rev)) ||
      !(arr = malloc(sizeof(char *) * (tab_len(seq) + 1))))
    return (ERROR);
  while (seq[j])
    {
      if (!(arr[w] = malloc(sizeof(char) * (strlen(seq[j] + 1)))))
	return (ERROR);
      if (!(arr =  transform_char(arr, seq[j], &w, 0)))
	return (ERROR);
      ++j;
    }
  arr[w] = NULL;
  sort_show_free(arr, seq);
  return (SUCCESS);
}
