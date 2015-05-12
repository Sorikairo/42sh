/*
** sum_params.c for Exo 03 in /home/fouhet_k/rendu/Piscine-C-Jour_08/ex_03
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Oct  9 19:47:58 2013 Kevin Fouhety
** Last update Tue Oct 22 08:12:07 2013 Kevin Fouhety
*/

#include <stdlib.h>

char	*sum_params(int argc, char **argv)
{
  int	i;
  int	j;
  char	*str;
  int	l;

  i = 0;
  j = 0;
  l = 0;
  while (j < argc)
    {
      l = l + 1 + my_strlen(argv[j]);
      j = j + 1;
    }
  str = malloc(l + 1);
  while (i < argc)
    {
      my_strcat(str, argv[i]);
      if (i != argc)
	my_strcat(str, "\n");
      else
	my_strcat(str, "\0");
      i = i + 1;
    }
  return (str);
}
