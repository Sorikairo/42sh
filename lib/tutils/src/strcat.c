/*
** strcat.c for tutils in /home/fourri_l/Projects/PSU_2013_minishell1/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Dec 17 21:34:45 2013 Laurent Fourrier
** Last update Tue Apr 22 10:28:52 2014 Laurent Fourrier
*/

#include "tutils.h"

char	*utl_strncat(char *dst, char *str, int n)
{
  int	dst_it;
  int	str_it;

  dst_it = 0;
  while (dst[dst_it] != '\0')
    dst_it++;
  str_it = 0;
  while (str_it < n)
    {
      dst[dst_it] = str[str_it];
      dst_it++;
      str_it++;
    }
  dst[dst_it] = '\0';
  return (dst);
}

char	*utl_strcat(char *dst, char *str)
{
  return (utl_strncat(dst, str, utl_strlen(str)));
}

char	*utl_strcatc(char *dst, char c)
{
  int	it;

  it = 0;
  while (dst[it])
    it++;
  dst[it++] = c;
  dst[it] = '\0';
  return (dst);
}
