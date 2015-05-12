/*
** count_slash.c for count_slash in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 13:31:59 2014 Barneaud Viveka
** Last update Tue May  6 13:32:48 2014 Barneaud Viveka
*/

#include	<stdlib.h>

int		count_slot(char **wtab)
{
  int		k;

  k = 0;
  while (wtab[k] != NULL)
    k++;
  return (k);
}

int		count_slash(char *str)
{
  int		s;
  int		i;

  i = 0;
  s = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	s++;
      i++;
    }
  return (s);
}
