/*
** my_put_nbr.c for Exo 07 in /home/fouhet_k/rendu/Piscine-C-Jour_03
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Oct  3 09:35:25 2013 Kevin Fouhety
** Last update Fri Dec 27 11:30:23 2013 Kevin Fouhety
*/

#include "my.h"

void	my_putnbr(int nb)
{
  char	rest;

  if (nb < 0)
    {
      my_putchar('-');
      rest = ((nb % 10) * -1) + '0';
      nb = nb / 10;
      nb = -nb;
      my_putnbr(nb);
      my_putchar(rest);
    }
  else if (nb >= 10)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
    my_putchar(48 + nb);
}
