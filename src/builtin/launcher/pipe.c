/*
** pipe.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar  8 09:18:08 2014 Laurent Fourrier
** Last update Sat May 24 15:18:12 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

pid_t	launch_pipe_in(t_cmd *cmd, t_system *sys, int prc_pipe[2])
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      close(prc_pipe[1]);
      if (dup2(prc_pipe[0], 0) == -1)
	return (pid);
      close(prc_pipe[0]);
      launch_cmd(cmd, sys);
    }
  return (pid);
}

pid_t	launch_pipe_out(t_cmd *cmd, t_system *sys, int prc_pipe[2])
{
  pid_t	pid;

  pid = fork();
  if (pid == 0)
    {
      close(prc_pipe[0]);
      if (dup2(prc_pipe[1], 1) == -1)
	return (pid);
      close(prc_pipe[1]);
      launch_cmd(cmd, sys);
    }
  return (pid);
}
