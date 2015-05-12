/*
** process_cmdlist.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 14:53:15 2014 Laurent Fourrier
** Last update Sat May 24 17:18:51 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

static void	activate_cursor(int activate)
{
  char		*str;

  str = tgetstr((activate) ? "ve" : "vi", NULL);
  if (str)
    write_str(g_fstdout, str);
  flush_file(g_fstdout);
}

int		process_cmdlist(t_cmd *cmd, t_system *sys)
{
  int		rtn;

  activate_cursor(TRUE);
  while (cmd != NULL)
    {
      rtn = launch_cmd(cmd, sys);
      if (rtn != SIGRTN_NOERR)
	return (rtn);
      while (cmd->next != NULL && is_chainloadable(cmd->nxtsym))
	cmd = cmd->next;
      cmd = cmd->next;
    }
  activate_cursor(FALSE);
  return (SIGRTN_NOERR);
}
