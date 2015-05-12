/*
** Print_int.c for my_printf in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 11:50:46 2013 Kevin Fouhety
** Last update Thu Nov 14 14:25:45 2013 Kevin Fouhety
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

void	my_dec(va_list ap)
{
  int	i;

  i = va_arg(ap, int);
  my_putnbr(i);
}

void	my_oct(va_list ap)
{
  int	i;
  char	*str;

  i = va_arg(ap, int);
  str = "01234567";
  my_putnbr_base(i, str);
}

void	my_hex_m(va_list ap)
{
  int	i;
  char	*str;

  i = va_arg(ap, int);
  str = "0123456789ABCDEF";
  my_putnbr_base(i, str);
}

void	my_hex(va_list ap)
{
  int	i;
  char	*str;

  i = va_arg(ap, int);
  str = "0123456789abcdef";
  my_putnbr_base(i, str);
}

void	my_bin(va_list ap)
{
  int	i;
  char	*base;

  i = va_arg(ap, int);
  base = "01";
  my_putnbr_base(i, base);
}
