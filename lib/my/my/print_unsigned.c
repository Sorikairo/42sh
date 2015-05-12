/*
** take_base.c for my_printf in /home/fouhet_k/Perso/printf
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Nov 13 13:44:30 2013 Kevin Fouhety
** Last update Thu Nov 14 14:26:01 2013 Kevin Fouhety
*/

#include <stdarg.h>
#include "my_printf.h"

void	my_unsi(va_list ap)
{
  unsigned int	i;

  i = va_arg(ap, unsigned int);
  my_putnbr_uns(i);
}

void	my_putnbr_uns(unsigned int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 10)
    {
      my_putnbr_uns(nb / 10);
      my_putnbr_uns(nb % 10);
    }
  else
    my_putchar(48 + nb);
}

void	my_putnbr_base_uns(long nbr, char *base)
{ 
  long	i;
  long	n;
  
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * (-1);
    }
  i = 0;
  n = 1;
  while ((nbr / n) >= my_strlen(base))
    n = n * my_strlen(base);
  while (n > 0)
    {
      i = (nbr / n) % my_strlen(base);
      my_putchar(base[i]);
      n = n / my_strlen(base);
    }
}
