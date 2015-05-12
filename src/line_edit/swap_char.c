/*
** swap_char.c for swap_char in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 14:47:52 2014 Barneaud Viveka
** Last update Sat May 24 17:58:26 2014 Barneaud Viveka
*/

#include	<tutils.h>
#include	"system.h"
#include	"line_editor.h"

char		*swap_char(t_system *av, char *nbuf)
{
  char		tmp;

  if (utl_strlen(nbuf) < 2)
    {
      my_printf("\a");
      return (nbuf);
    }
  if (g_pos == utl_strlen(nbuf))
    {
      tmp = nbuf[g_pos - 2];
      nbuf[g_pos - 2] = nbuf[g_pos - 1];
      nbuf[g_pos - 1] = tmp;
    }
  else
    {
      tmp = nbuf[g_pos - 1];
      nbuf[g_pos - 1] = nbuf[g_pos];
      nbuf[g_pos] = tmp;
      (g_pos)++;
    }
  return (nbuf);
}
