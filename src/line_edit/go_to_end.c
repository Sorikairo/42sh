/*
** go_to_end.c for go_to_end in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 14:35:53 2014 Barneaud Viveka
** Last update Wed May 21 12:00:31 2014 Kevin Fouhety
*/

#include	"system.h"
#include	"line_editor.h"

char		*goto_end(t_system *av, char *nbuf)
{
  int		i;

  i = g_pos;
  while (nbuf[i] != '\0')
    {
      i++;
      g_pos++;
    }
  return (nbuf);
}
