/*
** my_strdup.c for strdup in /home/fouhet_k/rendu/Piscine-C-Jour_08/ex_01
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Oct  9 09:36:34 2013 Kevin Fouhety
** Last update Sat Oct 26 18:07:06 2013 Kevin Fouhety
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  int	l;
  char	*str;

  i = 0;
  l = 0;
  while (src[i] != 0)
    {
      i = i + 1;
    }
  str = malloc(i);
  while (src[l] != '\0')
    {
      str[l] = src[l];
      l = l + 1;
    }
  str[l] = '\0';
  return (str);
}
