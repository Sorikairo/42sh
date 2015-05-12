/*
** lowerize.c for lowerize in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat May  3 14:30:47 2014 Barneaud Viveka
** Last update Sat May 24 11:43:19 2014 Barneaud Viveka
*/

#include	<string.h>
#include	<tutils.h>
#include	"autocompletion.h"

int		is_upper(char a)
{
  if (a >= 'A' && a <= 'Z')
    return (1);
  return (0);
}

char		*lowerize(char *str)
{
  char		*tmp;
  int		i;

  if ((tmp = malloc_str(sizeof(*tmp) * (utl_strlen(str) + 1))) == NULL)
    return (utl_strcpy("\0"));
  i = 0;
  while (str[i] != '\0')
    {
      if (is_upper(str[i]) == 1)
	tmp[i] = str[i] + 32;
      else
	tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
