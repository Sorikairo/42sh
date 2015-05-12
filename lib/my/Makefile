##
## Makefile for Exo 01 in /home/fouhet_k/rendu/Piscine-C-lib/my
## 
## Made by Kevin Fouhety
## Login   <fouhet_k@epitech.net>
## 
## Started on  Mon Oct 21 09:26:22 2013 Kevin Fouhety
## Last update Tue Apr 22 10:39:26 2014 Laurent Fourrier
##

CC	=	cc

RM	=	rm -f

CP	=	cp

NAME	=	libmy.a

SRCS	=	./my/my_putchar.c \
		./my/my_isneg.c \
		./my/my_put_nbr.c \
		./my/my_swap.c \
		./my/my_putstr.c \
		./my/my_strlen.c \
		./my/my_getnbr.c \
		./my/my_sort_int_tab.c \
		./my/my_power_rec.c \
		./my/my_square_root.c \
		./my/my_factorielle_rec.c \
		./my/my_is_prime.c \
		./my/my_find_prime_sup.c \
		./my/my_strcpy.c \
		./my/my_strncpy.c \
		./my/my_revstr.c \
		./my/my_strstr.c \
		./my/my_strcmp.c \
		./my/my_strncmp.c \
		./my/my_strupcase.c \
		./my/my_strlowcase.c \
		./my/my_strcapitalize.c \
		./my/my_str_isalpha.c \
		./my/my_str_isnum.c \
		./my/my_str_islower.c \
		./my/my_str_isupper.c \
		./my/my_str_isprintable.c \
		./my/my_showstr.c \
		./my/my_showmem.c \
		./my/my_strcat.c \
		./my/my_strncat.c \
		./my/my_strlcat.c \
		./my/my_strdup.c \
		./my/my_str_to_wordtab.c \
		./my/my_getnbr_base.c \
		./my/my_putnbr_base.c \
		./my/my_sort_int_tab.c \
		./my/my_sort_params.c \
		./printf/my_printf.c \
		./printf/print_unsigned.c \
		./printf/print_char.c \
		./printf/print_int.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Wall -Werror -ansi -pedantic -iquoteinclude

all:		$(CREATLIB) $(NAME)

$(CREATLIB):	$(OBJS)
	$(CC) $(OBJS)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
