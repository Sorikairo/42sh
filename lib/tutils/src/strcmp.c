/*
** strcmp.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  9 19:33:17 2013 Laurent Fourrier
** Last update Fri Apr 18 14:16:06 2014 Laurent Fourrier
*/

#include "tutils.h"

int	utl_strcmp(char *first, char *second)
{
  int	first_len;

  first_len = utl_strlen(first);
  return (utl_strncmp(first, second, first_len + 1));
}

int	utl_strncmp(char *first, char *second, int n)
{
  int	it;

  it = 0;
  while (it < n)
    {
      if (first[it] != second[it])
	return (first[it] - second[it]);
      it++;
    }
  return (0);
}
