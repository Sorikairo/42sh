/*
** varg.c for varg in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 09:08:49 2013 Kevin Fouhety
** Last update Thu Nov 14 14:30:46 2013 Kevin Fouhety
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

int	check_print(char st)
{
  if (st == 'd' || st == 'i')
    return (0);
  if (st == 'o')
    return (1);
  if (st == 'x')
    return (2);
  if (st == 'X')
    return (3);
  if (st == 'b')
    return (4);
  if (st == 's')
    return (5);
  if (st == 'c')
    return (6);
  if (st == 'p')
    return (7);
  if (st == 'S')
    return (8);
  if (st == 'u')
    return (9);
  return (10);
}

int	my_printf(const char *str, ...)
{
  void	(*fint[10])(va_list);
  va_list ap;
  int	d;

  fint[0] = &my_dec;
  fint[1] = &my_oct;
  fint[2] = &my_hex;
  fint[3] = &my_hex_m;
  fint[4] = &my_bin;
  fint[5] = &my_str;
  fint[6] = &my_char;
  fint[7] = &my_point;
  fint[8] = &my_str_no_print;
  fint[9] = &my_unsi;
  d = 0;
  va_start(ap, str);
  while (str[d] != '\0')
    if (str[d] == '%' && check_print(str[d + 1]) != 10)
      {
	fint[check_print(str[d + 1])](ap);
	d = d + 2;
      }
    else
      {
	if (str[d] == '%' && str[d + 1] == '%')
	  d = d + 1;
	my_putchar(str[d]);
	d = d + 1;
      }
  va_end(ap);
}
