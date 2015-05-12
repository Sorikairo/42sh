/*
** strcat_termios.c for 42sh in /home/fouhet_k/42sh/src/line_edit
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Apr  7 16:27:28 2014 Kevin Fouhety
** Last update Mon Apr  7 16:31:05 2014 Kevin Fouhety
*/

#include "line_editor.h"

char    *put_buffer_in_av(char *from, char *to, int pos)
{
  char  *ret;
  int   i;
  int   n;

  i = 0;
  n = 0;
  if ((ret = xmalloc(my_strlen(to) + 4)) == NULL)
    return (NULL);
  while (to[i] != '\0' && i < pos)
    {
      ret[i] = to[i];
      i++;
    }
  while (from[n] != '\0')
    ret[i++] = from[n++];
  while (to[i - n] != '\0')
    {
      ret[i] = to[i - n];
      i++;
    }
  ret[i] = '\0';
  free (to);
  return (ret);
}

char    *my_strcat_term(char *from, char *to, int pos)
{
  char  *ret;

  if (to == NULL)
    {
      if ((ret = xmalloc(2)) == NULL)
        return (NULL);
      ret[0] = from[0];
      ret[1] = '\0';
      return (ret);
    }
  else
    {
      ret = put_buffer_in_av(from, to, pos);
      return (ret);
    }
}
