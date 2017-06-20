/*
** useful.h for fastatools in /home/benoit.pingris/delivery/synthesis/fasta
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Sat Jun 17 21:38:39 2017 benoit pingris
** Last update Tue Jun 20 15:16:49 2017 benoit pingris
*/

#ifndef USEFUL_H_
# define USEFUL_H_

char	*mallocat(char *, char *);
char	*mallocncat(char *, char *, int);
char	*epur_str(char *);
char	*epur_dna(char *);
char	*uppercase(char *);
char	*put_null(char *, int);

char	**get_reverse(char **);
char	**tab_fusion(char **, char **);
char	**realloc_tab(char **, int);

int	putstr(char *, int, int);
int	showtab(char **);
int	good_char(char *);
int	tab_len(char **);
int	str_isnum(const char *);

void	sort_tab(char **);
void	free_tab(char **);
void	my_putchar(char);

#endif /* !USEFUL_H_ */
