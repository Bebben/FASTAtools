/*
** fasta.h for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:39:38 2017 benoit pingris
** Last update Tue Jun 20 12:56:29 2017 benoit pingris
*/

#ifndef FASTA_H_
# define FASTA_H_

int	err(const char **);
int	fasta_tools(const char **);

int	get_opt(const char **, char **);

int	show_dna(const char **, char **);
int	show_rna(const char **, char **);

void	reverse_tab(char **, int, int);
int	reverse(const char **, char **);

int	k_mers(const char **, char **);

int	sequence(const char **, char **);
int	amino_acids(const char **, char **);
int	dna_align(const char **, char **);

char	**get_sequence(char **);
char	**get_reverse(char **);

#endif /* !FASTA_H_ */
