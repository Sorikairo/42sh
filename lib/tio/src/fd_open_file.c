/*
** fd_open_file.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Jan 14 13:24:55 2014 Laurent Fourrier
** Last update Thu Feb  6 13:20:20 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include "tio.h"

void		init_file(t_file *file)
{
  if (file->mode & FILE_R)
    {
      file->bytes_read = (file->mode & FILE_NOPREREAD) ? 1 :
	read(file->fd, file->buf, FILE_BUFSIZE);
      file->buf_it = (file->mode & FILE_NOPREREAD) ? 1 : 0;
    }
  else if (file->mode & FILE_W)
    file->buf_it = 0;
}

t_file		*fd_open_file(int fd, int mode)
{
  t_file	*file;

  if ((file = ts_malloc(sizeof(t_file))) == NULL)
    return (NULL);
  file->fd = fd;
  file->mode = mode;
  init_file(file);
  return (file);
}
