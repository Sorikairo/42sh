/*
** print_char.c for my_printf in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 13:46:04 2013 Kevin Fouhety
** Last update Tue Apr 22 10:40:04 2014 Laurent Fourrier
*/

#include "my_printf.h"

int	my_str(va_list ap)
{
  char	*str;

  str = va_arg(ap, char *);
  my_putstr(str);
  return (my_strlen(str));
}

int	my_char(va_list ap)
{
  int	i;

  i = va_arg(ap, int);
  my_putchar(i);
  return (1);
}

int	my_str_no_print(va_list ap)
{
  char	*str;
  int	i;
  int	n;

  i = 0;
  n = 0;
  str = va_arg(ap, char *);
  while (str[i] != '\0')
    {
      if (str[i] < ' ' || str[i] >= 127)
	{
	  n = n + my_putchar('\\');
	  n = n + put_oct(str[i]);
	}
      else
	n = n + my_putchar(str[i]);
      i = i + 1;
    }
  return (n);
}

int	my_point(va_list ap)
{
  char	*base;
  long	str;
  int	n;

  n = 2;
  base = "0123456789abcdef";
  str = va_arg(ap, long);
  my_putstr("0x");
  n = n + my_putnbr_base_uns(str, base);
  return (n);
}

int	put_oct(char st)
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
	result[n] = '0';
      n = n - 1;
    }
  my_putstr(result);
  return (1);
}
