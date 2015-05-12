/*
** print_unsigned.c for my_printf in /home/fouhet_k/rendu/PSU_2013_my_printf/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Nov 14 15:34:33 2013 Kevin Fouhety
** Last update Tue Apr 22 10:39:52 2014 Laurent Fourrier
*/

#include "my_printf.h"

int	my_unsi(va_list ap)
{
  unsigned int	i;
  int	n;

  i = va_arg(ap, unsigned int);
  n = my_putnbr_uns(i);
  return (n);
}

int	my_putnbr_uns(unsigned int nb)
{
  unsigned int	i;
  unsigned int	n;
  int		k;

  k = 0;
  i = 0;
  n = 1;
  while ((nb / n) >= 10)
    n = n * 10;
  while (n > 0)
    {
      i = (nb / n) % 10;
      k = k + my_putchar(i + 48);
      n = n / 10;
    }
  return (k);
}

int	my_putnbr_base_uns(long nbr, char *base)
{
  long	i;
  long	n;
  int	k;

  k = 0;
  if (nbr < 0)
    {
      k = k + my_putchar('-');
      nbr = nbr * (-1);
    }
  i = 0;
  n = 1;
  while ((nbr / n) >= my_strlen(base))
    n = n * my_strlen(base);
  while (n > 0)
    {
      i = (nbr / n) % my_strlen(base);
      k = k + my_putchar(base[i]);
      n = n / my_strlen(base);
    }
  return (k);
}

int     my_putnbr_print(int nb)
{
  long	i;
  long	n;
  int	k;

  k = 0;
  if (nb < 0)
    {
      k = k + my_putchar('-');
      nb = nb * (-1);
    }
  i = 0;
  n = 1;
  while ((nb / n) >= 10)
    n = n * 10;
  while (n > 0)
    {
      i = (nb / n) % 10;
      k = k + my_putchar(i + 48);
      n = n / 10;
    }
  return (k);
}
