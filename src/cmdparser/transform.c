/*
** transform.c for 42sh in /home/fourri_l/Projects/42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun May 25 17:14:54 2014 Laurent Fourrier
** Last update Sun May 25 17:33:10 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "system.h"
#include "cmdparser.h"
#include "environment.h"

static char	*cmd_replace_home(char *cmd, char *home)
{
  char		*rtn;

  if ((rtn = ts_malloc(utl_strlen(home) + utl_strlen(cmd) + 1)) == NULL)
    return (NULL);
  rtn[0] = '\0';
  utl_strcat(rtn, home);
  utl_strcat(rtn, cmd + 1);
  free(cmd);
  return (rtn);
}

static void	cmd_check_home(t_cmd *cmd, char *home)
{
  int		it;

  if (cmd->cmd[0] == '~')
    cmd->cmd = cmd_replace_home(cmd->cmd, home);
  it = 0;
  while (cmd->args && cmd->args[it])
    {
      if (cmd->args[it][0] == '~')
	cmd->args[it] = cmd_replace_home(cmd->args[it], home);
      it++;
    }
}

void		cmd_transform(t_cmd *cmd, t_system *system)
{
  char		*home;

  home = env_get(system->env, "HOME");
  while (cmd)
    {
      if (home)
	cmd_check_home(cmd, home);
      cmd = cmd->next;
    }
}
