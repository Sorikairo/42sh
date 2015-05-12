/*
** unsetenv.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 21:44:57 2014 Laurent Fourrier
** Last update Mon Mar  3 21:47:07 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

int	builtin_unsetenv(t_cmd *cmd, t_system *sys)
{
  if (cmd->args[1] == NULL)
    {
      write_str(g_fstdout, "Usage: unsetenv VARIABLE\n");
      flush_file(g_fstdout);
      return (SIGRTN_NOERR);
    }
  sys->env = env_delete(sys->env, cmd->args[1]);
  return (SIGRTN_NOERR);
}
