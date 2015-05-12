/*
** my_putnbr_base.c for Exo 15 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Oct  8 09:43:36 2013 Kevin Fouhety
** Last update Fri Dec 27 11:54:37 2013 Kevin Fouhety
*/

#include "my.h"

void	my_putnbr_base(int nbr, char *base)
{
  int	i;
  int	n;

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
