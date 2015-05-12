/*
** redir.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar  8 09:21:13 2014 Laurent Fourrier
** Last update Wed May 28 10:34:23 2014 Laurent Fourrier
*/

/*
** Shitload of includes!
*/
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

static void	put_openerror(char *file)
{
  write_str(g_fstdout, file);
  write_str(g_fstdout, " : ");
  write_str(g_fstdout, strerror(errno));
  write_char(g_fstdout, '\n');
  flush_file(g_fstdout);
}

pid_t		launch_redir_in(t_cmd *cmd, t_system *sys,
				int prc_pipe[2], int ovrw)
{
  int		fd_out;
  pid_t		pid;

  (void)sys;
  pid = fork();
  if (pid == 0)
    {
      close(prc_pipe[1]);
      fd_out = open(cmd->cmd,
		    O_WRONLY | O_CREAT | ((ovrw) ? O_TRUNC : O_APPEND),
		    00644);
      if (fd_out == -1)
	put_openerror(cmd->cmd);
      redir_io(prc_pipe[0], fd_out);
      close(prc_pipe[0]);
      close(fd_out);
    }
  return (pid);
}

pid_t		launch_redir_out(t_cmd *cmd, t_system *sys, int prc_pipe[2])
{
  int		fd_in;
  pid_t		pid;

  (void)sys;
  pid = fork();
  if (pid == 0)
    {
      close(prc_pipe[0]);
      fd_in = open(cmd->cmd, O_RDONLY);
      if (fd_in == -1)
	put_openerror(cmd->cmd);
      redir_io(fd_in, prc_pipe[1]);
      close(prc_pipe[1]);
      close(fd_in);
    }
  return (pid);
}

pid_t		launch_redir_heredoc(t_cmd *cmd, t_system *sys, int prc_pipe[2])
{
  char		*eof;
  pid_t		pid;

  pid = fork();
  if (pid == 0)
    {
      close(prc_pipe[0]);
      if (cmd->args[0] != NULL)
	{
	  eof = utl_strcpy(cmd->args[0]);
	  destroy_wordarr(cmd->args);
	  cmd->args = ts_malloc(3 * sizeof(void*));
	  if (cmd->args)
	    {
	      cmd->args[0] = utl_itoa(prc_pipe[1]);
	      cmd->args[1] = eof;
	      cmd->args[2] = NULL;
	    }
	}
      builtin_heredoc(cmd, sys);
      close(prc_pipe[1]);
    }
  return (pid);
}
