/*
** my_putstr.c for Exo 02 in /home/fouhet_k/rendu/Piscine-C-Jour_04
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Oct  4 10:22:51 2013 Kevin Fouhety
** Last update Fri Dec 27 11:36:30 2013 Kevin Fouhety
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar (str[i]);
      i = i + 1;
    }
}
