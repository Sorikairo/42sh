/*
** buffer_work.c for 42sh in /home/fouhet_k/42sh/new42/repo-42sh/src/line_edit
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri May  9 14:24:53 2014 Kevin Fouhety
** Last update Sat May 24 11:55:38 2014 Kevin Fouhety
*/

#include <tutils.h>
#include "line_editor.h"
#include "autocompletion.h"
#include "prompt.h"
#include "keyboard.h"

char	*buffer_one_lenth(char *buffer, char *nbuf, t_system *av)
{
  if (buffer[0] == '\t')
    nbuf = autocompletion(nbuf, av);
  else if (buffer[0] == 127)
    nbuf = delet_last_char(nbuf, av, g_pos);
  else if (buffer[0] == 4)
    {
      if (nbuf[0] == '\0')
	{
	  free(nbuf);
	  return ("exit\n");
	}
      my_putchar('\a');
    }
  else
    nbuf = get_key_functs(nbuf, buffer, av);
  return (nbuf);
}

char	*buffer_three_lenth(char *buffer, char *nbuf, t_system *av)
{
  int	i;

  i = 0;
  if (buffer[2] == 68)
    g_pos = decrease_pos(g_pos);
  else if (buffer[2] == 67)
    g_pos = increase_pos(g_pos, nbuf);
  else if (buffer[2] == 65 || buffer[2] == 66)
    {
      restor_cursor_pos();
      while (i < (utl_strlen(nbuf) + utl_strlen(g_prompt.prompt) + 1))
	my_printf(" ", i++);
      nbuf = reprint_cmd(buffer, av, nbuf);
      g_pos = utl_strlen(nbuf);
    }
  return (nbuf);
}
