/*
** my_swap.c for Exo 1 in /home/fouhet_k/rendu/Piscine-C-Jour_04
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Oct  3 11:09:19 2013 Kevin Fouhety
** Last update Fri Dec 27 11:34:08 2013 Kevin Fouhety
*/

#include "my.h"

void	my_swap(char a, char b)
{
  int	swap;

  swap = a;
  a = b;
  b = swap;
}
