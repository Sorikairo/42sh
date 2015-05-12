/*
** my_putchar.c for putchar in /home/fouhet_k/rendu/Piscine-C-lib/my
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct 21 10:39:28 2013 Kevin Fouhety
** Last update Fri Dec 27 11:22:04 2013 Kevin Fouhety
*/

#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
