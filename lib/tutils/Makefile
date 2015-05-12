##
## Makefile for tutils in /home/fourri_l/Projects/lib/tutils
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Fri Dec  6 13:46:22 2013 Laurent Fourrier
## Last update Thu Apr  3 17:12:01 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote${INCDIR} \
		-I${LIBDIR}/include

SRC	=	$(SRCDIR)/atod.c \
		$(SRCDIR)/atoi.c \
		$(SRCDIR)/destroy_wordarr.c \
		$(SRCDIR)/fmt_get_next_word.c \
		$(SRCDIR)/fmt_str_to_wordarr.c \
		$(SRCDIR)/get_next_line.c \
		$(SRCDIR)/get_wordarr_len.c \
		$(SRCDIR)/itoa.c \
		$(SRCDIR)/rand_memory.c \
		$(SRCDIR)/rand_vneumann.c \
		$(SRCDIR)/strcat.c \
		$(SRCDIR)/strcmp.c \
		$(SRCDIR)/strcpy.c \
		$(SRCDIR)/strdelc.c \
		$(SRCDIR)/strisnbr.c \
		$(SRCDIR)/strisvalid.c \
		$(SRCDIR)/strlen.c \
		$(SRCDIR)/str_to_wordarr.c \
		$(SRCDIR)/wordarr_cpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtutils.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
