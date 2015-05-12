/*
** is_readable.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:41:02 2013 Laurent Fourrier
** Last update Sat Dec 28 15:04:55 2013 Laurent Fourrier
*/

#include "tio.h"

int	is_readable(t_file *file)
{
  return ((file->mode & FILE_R) && (file->bytes_read > 0));
}
