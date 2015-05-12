/*
** my_strcat.c for Exo 01.1 in /home/fouhet_k/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue Oct  8 10:02:05 2013 Kevin Fouhety
** Last update Fri Dec 27 11:47:44 2013 Kevin Fouhety
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	l;
  
  i = 0;
  l = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[i + l] = src[i];
      i = i + 1;
    }
  dest[l + i] = '\0';
  return (dest);
}
