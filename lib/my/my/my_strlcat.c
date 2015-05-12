/*
** my_strlcat.c for Exo 01_3 in /home/fouhet_k/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Oct  8 13:13:53 2013 Kevin Fouhety
** Last update Fri Dec 27 11:48:21 2013 Kevin Fouhety
*/

#include "my.h"

char	*my_strlcat(char *dest, char *src, int size)
{
  int	i;
  int	l;

  i = 0;
  l = my_strlen(dest);
  while (src[i] != '\0' && (i + l) < size)
    {
      dest[i + l] = src[i];
      i = i + 1;
    }
  dest[size] = '\0';
  return (dest);
}
