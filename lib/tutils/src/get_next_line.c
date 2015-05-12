/*
** get_next_line.c for get_next_line in /home/fourri_l/Projects/get_next_line-2018-fourri_l
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Nov 18 10:09:03 2013 Laurent Fourrier
** Last update Fri Dec  6 18:43:08 2013 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>

#define GNL_BUFSIZE 1024

int		read_to_buf(const int fd, char *buf, int *it)
{
  *it = 0;
  return (read(fd, buf, GNL_BUFSIZE));
}

char		*get_next_line(const int fd)
{
  static char	buf[GNL_BUFSIZE];
  static int	it = -1;
  static int	bytes_read = 0;
  char		*rtn;
  int		rtn_it;

  if (it == -1 || it == bytes_read)
    bytes_read = read_to_buf(fd, buf, &it);
  if ((rtn = malloc(GNL_BUFSIZE)) == NULL || bytes_read == 0)
    return (NULL);
  rtn_it = 0;
  while (bytes_read > 0 && buf[it] != '\n')
    {
      rtn[rtn_it] = buf[it];
      it++;
      rtn_it++;
      if (rtn_it % GNL_BUFSIZE == 0)
	rtn = ts_realloc(rtn, rtn_it, rtn_it + 1 + GNL_BUFSIZE);
      if (it == bytes_read)
	bytes_read = read_to_buf(fd, buf, &it);
    }
  rtn[rtn_it] = '\0';
  it++;
  return (rtn);
}
