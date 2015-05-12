/*
** my_isneg.c for Exo 04 in /home/fouhet_k/rendu/Piscine-C-Jour_03
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Oct  2 11:00:25 2013 Kevin Fouhety
** Last update Fri Dec 27 11:30:29 2013 Kevin Fouhety
*/

#include "my.h"

int	my_isneg(int n)
{
  int	nb;

  nb = 'P';
  if (n < 0)
    {
      nb = 'N';
    }
  my_putchar(nb);
  return 0;
}
