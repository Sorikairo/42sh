/*
** my_termios.c for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/minishell
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:25:44 2014 Kevin Fouhety
** Last update Sun May 25 14:32:06 2014 Kevin Fouhety
*/

#include <tio.h>
#include <tutils.h>
#include <string.h>
#include "prompt.h"
#include "line_editor.h"

char	*g_nbuf;

int	decrease_pos(int pos)
{
  if (pos > 0)
    return (pos - 1);
  else
    my_putchar('\a');
  return (pos);
}

int	increase_pos(int pos, char *buf)
{
  int	max;

  max = utl_strlen(buf);
  if (pos < max && max != 0)
    return (pos + 1);
  else
    my_putchar('\a');
  return (pos);
}

void    use_signal(int i)
{
  char	*test;

  if (i == SIGINT)
    {
      if (g_nbuf != NULL)
	{
	  g_pos = -1;
	  my_printf("\b^C\n");
	  save_the_line();
	  free(g_nbuf);
	  g_nbuf = utl_strcpy("");
	  print_promp_buffer(g_nbuf);
	  g_pos = 0;
	}
    }
  else if (i == SIGWINCH)
    {
      test = tgetstr("cd", NULL);
      my_putstr(test);
      restor_cursor_pos();
      print_promp_buffer(g_nbuf);
    }
}

void	take_signal()
{
  signal(SIGWINCH, use_signal);
  signal(SIGINT, use_signal);
  signal(SIGTSTP, SIG_IGN);
}

char    *my_read_inf(t_system *av, t_term *term)
{
  int           ret;
  char          buffer[5];

  g_nbuf = utl_strcpy("");
  buffer[0] = '\0';
  take_signal();
  while (buffer[0] != 13)
    {
      print_promp_buffer(g_nbuf);
      ret = read(0, buffer, 10);
      buffer[ret] = '\0';
      if (buffer[0] != '\n' && buffer[0] >= ' ' &&
	  buffer[0] < 127 && my_strlen(buffer) == 1)
	{
	  if ((g_nbuf = my_strcat_term(buffer, g_nbuf, g_pos)) == NULL)
	    return (g_nbuf = utl_strcpy(""));
	  g_pos++;
	}
      else
	g_nbuf = work_on_nbuf(g_nbuf, av, term, buffer);
      if (utl_strcmp("exit\n", g_nbuf) == 0)
        return (utl_strcpy("exit"));
    }
  av->pos_in_history = 0;
  return (g_nbuf);
}
