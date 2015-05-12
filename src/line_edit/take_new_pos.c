/*
** take_new_pos.c for 42sh in /home/fouhet_k/42sh/repo-42sh
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Tue May 20 15:13:50 2014 Kevin Fouhety
** Last update Sat May 24 17:58:53 2014 Barneaud Viveka
*/

#include <tutils.h>
#include "line_editor.h"

int	take_left_pos(char *nbuf, int pos)
{
  int	ret;

  ret = pos;
  while (ret != 0 && nbuf[--ret] == ' ');
  if (ret == 0)
    my_printf("\a");
  else
    while (ret != 0 && nbuf[ret] != ' ')
      ret--;
  if (ret != 0)
    ret++;
  return (ret);
}

int	take_right_pos(char *nbuf, int pos)
{
  int	ret;

  ret = pos;
  while (nbuf[ret] != '\0' && nbuf[ret] == ' ')
    ret++;
  if (ret == utl_strlen(nbuf))
    my_printf("\a");
  else
    while (nbuf[ret] != '\0' && nbuf[ret] != ' ')
      ret++;
  return (ret);
}

int	take_new_pos(char *nbuf, int pos, char arrow)
{
  int	ret;

  ret = pos;
  if (arrow == 68)
    ret = take_left_pos(nbuf, pos);
  else if (arrow == 67)
    ret = take_right_pos(nbuf, pos);
  return (ret);
}
