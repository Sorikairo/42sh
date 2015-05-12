/*
** launch_redir_right.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar  8 09:02:51 2014 Laurent Fourrier
** Last update Sat May 24 16:02:06 2014 Barneaud Viveka
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

int	launch_redir_right(t_cmd *cmd, t_system *sys)
{
  int	prc_pipe[2];
  pid_t	first;
  pid_t	second;

  if (pipe(prc_pipe) == -1)
    return (SIGRTN_NOERR);
  sys->wait = 0;
  first = launch_redir_in(cmd->next, sys, prc_pipe,
			  (cmd->nxtsym == 5) ? 0 : 1);
  if (first == 0)
    return (SIGRTN_EXIT);
  remove_nxtcmd(cmd);
  second = launch_pipe_out(cmd, sys, prc_pipe);
  if (second == 0)
    return (SIGRTN_EXIT);
  close(prc_pipe[0]);
  close(prc_pipe[1]);
  wait_proc(sys, first);
  wait_proc(sys, second);
  sys->wait = 1;
  return (SIGRTN_NOERR);
}
