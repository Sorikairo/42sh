/*
** setenv.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 13:11:30 2014 Laurent Fourrier
** Last update Mon Mar  3 18:52:02 2014 Laurent Fourrier
*/

#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

int	builtin_setenv(t_cmd *cmd, t_system *sys)
{
  int	argc;

  argc = get_wordarr_len(cmd->args);
  if (argc < 3)
    {
      write_str(g_fstdout, "Usage: setenv VARIABLE VALUE\n");
      flush_file(g_fstdout);
      return (SIGRTN_NOERR);
    }
  sys->env = env_set(sys->env, cmd->args[1], cmd->args[2]);
  return (SIGRTN_NOERR);
}
