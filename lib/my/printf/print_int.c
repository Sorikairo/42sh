/*
** print_int.c for my_printf in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 11:50:46 2013 Kevin Fouhety
** Last update Tue Apr 22 10:40:19 2014 Laurent Fourrier
*/

#include "my_printf.h"

int	my_dec(va_list ap)
{
  int	i;
  int	lengh;

  lengh = 0;
  i = va_arg(ap, int);
  lengh = my_putnbr_print(i);
  return (lengh);
}

int	my_oct(va_list ap)
{
  unsigned int	i;
  char	*str;
  int	n;

  i = va_arg(ap, int);
  str = "01234567";
  n = my_putnbr_base_uns(i, str);
  return (n);
}

int	my_hex_m(va_list ap)
{
  unsigned int	i;
  char	*str;
  int	n;

  i = va_arg(ap, int);
  str = "0123456789ABCDEF";
  n = my_putnbr_base_uns(i, str);
  return (n);
}

int	my_hex(va_list ap)
{
  unsigned int	i;
  char	*str;
  int	n;

  i = va_arg(ap, int);
  str = "0123456789abcdef";
  n = my_putnbr_base_uns(i, str);
  return (n);
}

int	my_bin(va_list ap)
{
  unsigned int	i;
  char	*base;
  int	n;

  i = va_arg(ap, int);
  base = "01";
  n = my_putnbr_base_uns(i, base);
  return (n);
}
