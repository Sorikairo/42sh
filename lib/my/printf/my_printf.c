/*
** my_printf.c for my_printf in /home/fouhet_k/rendu/PSU_2013_my_printf/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Nov 14 15:34:57 2013 Kevin Fouhety
** Last update Fri Dec 27 12:01:49 2013 Kevin Fouhety
*/

#include "my_printf.h"

int	check_print(char st)
{
  int	i;
  char	*str;

  i = 0;
  str = "dioxXbscpSu";
  while (str[i] != '\0')
    {
      if (str[i] == st)
	return (i);
      else
	i = i + 1;
    }
  return (11);
}

void	finit_f(int (**fint)(va_list va))
{
  fint[0] = &my_dec;
  fint[1] = &my_dec;
  fint[2] = &my_oct;
  fint[3] = &my_hex;
  fint[4] = &my_hex_m;
  fint[5] = &my_bin;
  fint[6] = &my_str;
  fint[7] = &my_char;
  fint[8] = &my_point;
  fint[9] = &my_str_no_print;
  fint[10] = &my_unsi;
}

int	my_printf(const char *str, ...)
{
  int	(*fi[11])(va_list);
  va_list ap;
  int	d;
  int	j;

  finit_f(fi);
  d = 0;
  j = 0;
  va_start(ap, str);
  while (str[d] != '\0')
    if (str[d] == '%' && check_print(str[d + 1]) != 11)
      {
	j = j + fi[check_print(str[d + 1])](ap);
	d = d + 2;
      }
    else
      {
	if (str[d] == '%' && str[d + 1] == '%')
	  d = d + 1;
	j = j + my_putchar(str[d]);
	d = d + 1;
      }
  va_end(ap);
  return (j);
}
