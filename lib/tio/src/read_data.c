/*
** read_data.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Jan 24 19:19:33 2014 Laurent Fourrier
** Last update Thu Feb 27 14:49:10 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "tio.h"

void	*read_data(t_file *file, void *data, int size)
{
  char	*byte_data;
  int	it;

  if (data == NULL && (data = ts_malloc(size * sizeof(void*))) == NULL)
    return (NULL);
  it = 0;
  byte_data = data;
  while (it < size)
    byte_data[it++] = is_readable(file) ? read_char(file) : 0;
  return (data);
}
