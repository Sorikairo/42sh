##
## Makefile for tio in /home/fourri_l/Projects/lib/tio
## 
## Made by Laurent Fourrier
## Login   <fourri_l@epitech.net>
## 
## Started on  Mon Dec  9 17:27:21 2013 Laurent Fourrier
## Last update Thu Mar 20 14:36:24 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

LIBDIR	=	lib

SRCDIR	=	src

INCDIR	=	include

CFLAGS	=	-Wall -pedantic \
		-iquote$(INCDIR) \
		-I$(LIBDIR)/include

SRC	=	$(SRCDIR)/close_file.c \
		$(SRCDIR)/close_fstd.c \
		$(SRCDIR)/fd_open_file.c \
		$(SRCDIR)/flush_file.c \
		$(SRCDIR)/get_openflags.c \
		$(SRCDIR)/is_readable.c \
		$(SRCDIR)/is_writable.c \
		$(SRCDIR)/open_file.c \
		$(SRCDIR)/open_fstd.c \
		$(SRCDIR)/read_char.c \
		$(SRCDIR)/read_data.c \
		$(SRCDIR)/read_line.c \
		$(SRCDIR)/read_word.c \
		$(SRCDIR)/write_char.c \
		$(SRCDIR)/write_data.c \
		$(SRCDIR)/write_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtio.a

all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
