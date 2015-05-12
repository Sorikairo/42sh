/*
** read_char.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 15:13:00 2013 Laurent Fourrier
** Last update Sat Mar  8 11:19:21 2014 Laurent Fourrier
*/

#include <unistd.h>
#include "tio.h"

char	read_char(t_file *file)
{
  if (!is_readable(file))
    return ('\0');
  if (file->buf_it == file->bytes_read)
    {
      if ((file->bytes_read = read(file->fd, file->buf, FILE_BUFSIZE)) < 1)
	return ('\0');
      file->buf_it = 0;
    }
  return (file->buf[file->buf_it++]);
}
