/*
** launch_cmd.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Mar  7 16:55:49 2014 Laurent Fourrier
** Last update Sat May 24 17:07:49 2014 Laurent Fourrier
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

t_builtin	g_builtin[] =
  {
    {"exit", &builtin_exit, 0},
    {"env", &builtin_env, 0},
    {"setenv", &builtin_setenv, 0},
    {"unsetenv", &builtin_unsetenv, 0},
    {"cd", &builtin_chdir, 0},
    {"alias", &builtin_alias, 0},
    {"unalias", &builtin_unalias},
    {"history", &builtin_history, 0},
    {NULL, &builtin_launch, 1}
  };

t_launcher	g_launcher[] =
  {
    {SYM_PIPE, &launch_pipe},
    {SYM_REDIR_RGT, &launch_redir_right},
    {SYM_REDIR_ORGT, &launch_redir_right},
    {SYM_REDIR_LFT, &launch_redir_left},
    {SYM_REDIR_OLFT, &launch_redir_left},
    {SYM_BIN_AND, &launch_binary},
    {SYM_BIN_OR, &launch_binary},
    {SYM_NONE, NULL}
  };

static t_builtin	get_builtin(t_cmd *cmd)
{
  int			it;

  it = 0;
  while (g_builtin[it].cmd != NULL)
    {
      if (utl_strcmp(g_builtin[it].cmd, cmd->cmd) == 0)
	return (g_builtin[it]);
      it++;
    }
  return (g_builtin[it]);
}

static t_launcher	get_launcher(char sym)
{
  int			it;

  it = 0;
  while (g_launcher[it].sym)
    {
      if (g_launcher[it].sym == sym)
	return (g_launcher[it]);
      it++;
    }
  return (g_launcher[it]);
}

int			launch_cmd_fork(t_cmd *cmd, t_system *sys,
					t_builtin builtin)
{
  pid_t			pid;

  pid = fork();
  if (pid == 0)
    {
      builtin.func(cmd, sys);
      return (SIGRTN_EXIT);
    }
  else
    {
      wait_proc(sys, pid);
      return (SIGRTN_NOERR);
    }
}

int			launch_cmd(t_cmd *cmd, t_system *sys)
{
  t_builtin		builtin;
  t_launcher		launcher;

  launcher = get_launcher(cmd->nxtsym);
  if (launcher.sym == SYM_NONE)
    {
      builtin = get_builtin(cmd);
      return ((builtin.fork && sys->wait) ?
	      launch_cmd_fork(cmd, sys, builtin) :
	      builtin.func(cmd, sys));
    }
  return (launcher.func(cmd, sys));
}
