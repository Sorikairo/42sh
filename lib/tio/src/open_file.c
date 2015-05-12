/*
** open_file.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 14:08:55 2013 Laurent Fourrier
** Last update Tue Jan 14 13:42:56 2014 Laurent Fourrier
*/

#include <fcntl.h>
#include <stdlib.h>
#include <tsys.h>
#include "tio.h"

t_file	*open_file(char *path, int mode)
{
  int	fd;

  if ((fd = open(path, get_openflags(mode), 00644)) == -1)
    {
      put_error("Couldn't open file");
      return (NULL);
    }
  return (fd_open_file(fd, mode));
}
