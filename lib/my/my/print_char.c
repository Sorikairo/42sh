/*
** Print_char.c for my_printf in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 13:46:04 2013 Kevin Fouhety
** Last update Thu Nov 14 14:25:29 2013 Kevin Fouhety
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my_printf.h"

void	my_str(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  my_putstr(str);
}

void	my_char(va_list ap)
{
  int	i;

  i = va_arg(ap, int);
  my_putchar(i);
}

void	my_str_no_print(va_list ap)
{
  char	*str;
  int	i;
  
  i = 0;
  str = va_arg(ap, char *);
  while (str[i] != '\0')
    {
      if (str[i] < ' ' || str[i] >= 127)
	{
	  my_putchar('\\');
	  put_oct(str[i]);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

void	my_point(va_list ap)
{
  char	*base;
  long	str;

  base = "0123456789abcdef";
  str = va_arg(ap, long);
  my_putstr("0x");
  my_putnbr_base_uns(str, base);
}

void	put_oct(char st)
{
  int	i;
  char	result[4];
  int	n;

  i = st;
  n = 2;
  while (n >= 0)
    {
      result[n] = (i % 8) + 48;
      i = i / 8;
      if (n >= 0 && i == 0)
	result[n] == '0';
      n = n - 1;
    }
  my_putstr(result);
}
