##
## Makefile for tsys in /home/fourri_l/Projects/lib/tsys
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Mon Dec  2 17:14:51 2013 Laurent Fourrier
## Last update Mon Feb  3 11:27:43 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR)

SRC	=	$(SRCDIR)/malloc.c \
		$(SRCDIR)/memcpy.c \
		$(SRCDIR)/realloc.c \
		$(SRCDIR)/put_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtsys.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
