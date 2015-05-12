/*
** close_file.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:15:52 2013 Laurent Fourrier
** Last update Sat Dec 28 15:33:03 2013 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include "tio.h"

void	close_file(t_file *file)
{
  if (close(file->fd) == -1)
    put_error("Couldn't close file");
  free(file);
}
