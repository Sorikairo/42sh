/*
** my_printf.h for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:28:00 2014 Kevin Fouhety
** Last update Thu Mar  6 13:28:01 2014 Kevin Fouhety
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdarg.h>
# include <stdlib.h>
# include "my.h"

int	check_print(char);
int	my_dec(va_list);
int	my_oct(va_list);
int	my_hex(va_list);
int	my_bin(va_list);
int	take_base(int, char *);
int	my_hex_m(va_list);
int	my_str(va_list);
int	my_char(va_list);
int	my_str_no_print(va_list);
int	my_point(va_list);
int	my_no_arg(va_list);
int	put_oct(char);
int	my_unsi(va_list);
int	my_putnbr_uns(unsigned int);
int	my_putnbr_print(int);
int	my_putnbr_base_uns(long, char *);
void	finit_f(int (**)(va_list));

#endif /* !MY_PRINTF_H_ */
