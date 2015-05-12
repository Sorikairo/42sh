/*
** flush_file.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb  5 14:01:36 2014 Laurent Fourrier
** Last update Wed Feb  5 15:39:02 2014 Laurent Fourrier
*/

#include <unistd.h>
#include "tio.h"

void	flush_file(t_file *file)
{
  write(file->fd, file->buf, file->buf_it);
  file->buf_it = 0;
}
