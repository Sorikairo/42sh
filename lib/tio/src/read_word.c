/*
** read_word.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:28:23 2014 Laurent Fourrier
** Last update Mon Apr  7 14:42:58 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "tio.h"

char	rword_is_separator(char c, char *seps)
{
  while (*seps)
    {
      if (*seps == c)
	return (1);
      seps++;
    }
  return (0);
}

char	*read_word(t_file *file, char *seps)
{
  char	cur;
  char	*rtn;
  int	it;

  if (!is_readable(file))
    return (NULL);
  it = 0;
  if ((rtn = ts_malloc(FILE_BUFSIZE + 1)) == NULL)
    return (NULL);
  while (is_readable(file) && (cur = read_char(file)) &&
	 !rword_is_separator(cur, seps))
    {
      if ((it % FILE_BUFSIZE) == 0)
	{
	  if ((rtn = ts_realloc(rtn, it, it + FILE_BUFSIZE + 1)) == NULL)
	    return (NULL);
	}
      rtn[it++] = cur;
    }
  rtn[it] = '\0';
  return (rtn);
}
