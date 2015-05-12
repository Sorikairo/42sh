/*
** realloc.c for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  2 17:05:47 2013 Laurent Fourrier
** Last update Fri Apr 18 13:20:26 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tsys.h"

void	*ts_realloc(void *mem, int old_size, int new_size)
{
  char	*new_mem;

  new_mem = malloc(new_size);
  ts_memcpy(mem, new_mem, old_size);
  free(mem);
  return (new_mem);
}
