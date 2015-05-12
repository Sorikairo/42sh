/*
** getcmd.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 18:42:11 2014 Laurent Fourrier
** Last update Sun May 25 16:51:27 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "cmdparser.h"
#include "prompt.h"
#include "builtin.h"
#include "my_printf.h"
#include "line_editor.h"

int		g_pos;

void		print_line_cmd(char *line)
{
  restor_cursor_pos();
  if (utl_strcmp("exit\n", line) == 0)
    {
      free (g_nbuf);
      line = utl_strcpy("exit");
    }
  if (utl_strcmp("exit", line) == 0)
    my_printf("%s", g_prompt.prompt);
  else
    my_printf("%s%s \b", g_prompt.prompt, line);
}

char		*save_the_line()
{
  char		*start;

  if ((start = tgetstr("sc", NULL)) != NULL)
    if ((start = tgoto(start, 0, 0)) != NULL)
      {
	my_putstr(start);
	return ("ok");
      }
  my_putstr("Error, save the line\n");
  g_nbuf = utl_strcpy("exit");
  return (NULL);
}

static t_cmd	*prompt_getcmd_fallback(t_system *av)
{
  char		*line;
  t_cmd		*rtn;

  line = read_line(g_fstdin);
  if (line == NULL)
    {
      if ((rtn = ts_malloc(sizeof(t_cmd))) == NULL)
	return (NULL);
      rtn->cmd = utl_strcpy("exit");
      rtn->args = str_to_wordarr(rtn->cmd, "");
      rtn->nxtsym = SYM_NONE;
      rtn->next = NULL;
      return (rtn);
    }
  rtn = cmd_parse(line, av);
  free(line);
  return (rtn);
}

t_cmd		*prompt_getcmd(t_term *term, t_system *av)
{
  char		*line;
  t_cmd		*rtn;

  if (term == NULL)
    return (prompt_getcmd_fallback(av));
  else
    {
      put_read_term(term);
      g_pos = 0;
      if ((save_the_line()) != NULL)
	line = my_read_inf(av, term);
      print_line_cmd(line);
      put_old_term(term);
    }
  if (utl_strncmp(line, "\0", 1) != 0)
    av->history = stack_history(av->history, line);
  rtn = cmd_parse(line, av);
  if (g_nbuf != NULL)
    {
      free(line);
      g_nbuf = NULL;
    }
  if (term != NULL)
    my_printf("\n");
  return (rtn);
}
