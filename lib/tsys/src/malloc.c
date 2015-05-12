/*
** malloc.c for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  9 18:50:52 2013 Laurent Fourrier
** Last update Sat Dec 28 13:53:53 2013 Laurent Fourrier
*/

#include <stdlib.h>
#include "tsys.h"

void	*ts_malloc(int size)
{
  void	*rtn;

  rtn = malloc(size);
  if (rtn == NULL)
    put_error("Could not allocate memory");
  return (rtn);
}
