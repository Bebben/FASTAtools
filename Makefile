##
## Makefile for FASTAtools in /home/benoit.pingris/delivery/synthesis/fasta
## 
## Made by benoit pingris
## Login   <benoit.pingris@epitech.net>
## 
## Started on  Sat Jun 17 21:26:42 2017 benoit pingris
## Last update Tue Jun 20 15:10:23 2017 benoit pingris
##

CC	=	gcc

NAME	=	FASTAtools

SRC	=	src/main.c		\
		src/reverse.c		\
		src/err.c		\
		src/fasta.c		\
		src/sequence.c		\
		src/k_mers.c		\
		src/acids.c		\
		src/get_opt.c		\
		src/dna_rna.c		\
		src/useful/sorting.c	\
		src/useful/tab_fusion.c	\
		src/useful/epur_str.c	\
		src/useful/my_realloc.c	\
		src/useful/mallocat.c	\
		src/useful/free.c	\
		src/useful/is_num.c	\
		src/useful/putstr.c	\
		src/useful/format.c	\
		src/gnl/gnl.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include -Wall -Wextra

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

