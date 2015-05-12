/*
** write_data.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb  5 14:16:15 2014 Laurent Fourrier
** Last update Tue Apr  1 14:24:53 2014 Laurent Fourrier
*/

#include "tio.h"

void	write_data(t_file *file, void *data, int size)
{
  char	*byte_data;
  int	it;

  it = 0;
  byte_data = data;
  while (it < size)
    write_char(file, byte_data[it++]);
}
