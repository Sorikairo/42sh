/*
** strcpy.c for tutils in /home/fourri_l/Projects/PSU_2013_minishell1/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Dec 17 16:48:42 2013 Laurent Fourrier
** Last update Tue Dec 17 21:50:25 2013 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "tutils.h"

char	*utl_strncpy(char *str, int n)
{
  char	*rtn;
  int	it;

  if ((rtn = ts_malloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  it = 0;
  while (it < n)
    {
      rtn[it] = str[it];
      it++;
    }
  rtn[it] = '\0';
  return (rtn);
}

char	*utl_strcpy(char *str)
{
  return (utl_strncpy(str, utl_strlen(str)));
}
