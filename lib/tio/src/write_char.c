/*
** write_char.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb  5 13:47:48 2014 Laurent Fourrier
** Last update Wed Feb  5 15:39:20 2014 Laurent Fourrier
*/

#include "tio.h"

void	write_char(t_file *file, char c)
{
  if (is_writable(file))
    {
      if (file->buf_it == FILE_BUFSIZE)
	flush_file(file);
      file->buf[file->buf_it] = c;
      file->buf_it++;
    }
}
