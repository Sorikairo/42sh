##
## Makefile for tlist in /home/fourri_l/Projects/lib/tlist
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Thu Jan 23 10:14:22 2014 Laurent Fourrier
## Last update Thu May  1 19:39:41 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR) \
		-I$(LIBDIR)/include

SRC	=	$(SRCDIR)/add.c \
		$(SRCDIR)/iterate.c \
		$(SRCDIR)/remove.c \
		$(SRCDIR)/remove_dta.c \
		$(SRCDIR)/remove_dtacmp.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtlist.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
