/*
** completion_xdir.c for completion_xdir in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Fri May 16 11:06:57 2014 Barneaud Viveka
** Last update Fri May 16 11:36:48 2014 Barneaud Viveka
*/

#include	"line_editor.h"
#include	"autocompletion.h"

int		is_xdir(t_buf_parts bufp, char *fname)
{
  if (is_dir(bufp, fname) == 0 ||
      is_exe(bufp, fname) == 0)
    return (0);
  return (1);
}

char		*completion_xdir(char *nbuf, t_buf_parts bufp, t_system *av)
{
  if (count_xdir(bufp) == 1)
    nbuf = new_buffer(bufp, av);
  else if (count_xdir(bufp) == 0)
    my_printf("\nCannot find any executable or directory\n");
  else
    show_xdir(bufp);
  free_buf_parts(&bufp);
  return (nbuf);
}
