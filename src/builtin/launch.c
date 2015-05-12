/*
** launch.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 14:10:05 2014 Laurent Fourrier
** Last update Sat May 24 19:43:36 2014 Barneaud Viveka
*/

#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <tutils.h>
#include <tio.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "autocompletion.h"

int	launch_not_found(t_cmd *cmd)
{
  write_str(g_fstdout, "Error: command ");
  write_str(g_fstdout, cmd->cmd);
  write_str(g_fstdout, " not found.\n");
  flush_file(g_fstdout);
  return (SIGRTN_NOTFND);
}

char	*get_value(char *name, char **env)
{
  int	k;
  int	i;
  int	j;
  char	*ret;

  k = 0;
  while (env[k] != NULL)
    {
      if (strncmp(name, env[k], utl_strlen(name)) == 0)
	{
	  if ((ret = malloc_str(sizeof(*ret) *
				(utl_strlen(env[k]) + 1))) == NULL)
	    return (name);
	  i = 0;
	  j = 0;
	  while (i <= utl_strlen(name) && env[k][i] != 0)
	    i++;
	  while (env[k][i] != 0)
	    ret[j++] = env[k][i++];
	  ret[j] = 0;
	  return (ret);
	}
      k++;
    }
  return (name);
}

void	args_modifier(t_cmd *cmd, char *name, t_system *sys, int k)
{
  char	**wtab;
  char	*env_val;
  int	check;

  check = 0;
  env_val = get_value(name, sys->env);
  if (utl_strcmp(env_val, name) == 0)
    {
      env_val = strdup("\0");
      check = 1;
    }
  wtab = my_str_to_wtab(env_val, " \t\n");
  if (wtab == NULL)
    return;
  if (check == 0)
    cmd->args = add_files_to_args(cmd->args, wtab, k);
}

void	get_env_var(t_cmd *cmd, t_system *sys)
{
  char	*tp;
  int	k;
  int	i;
  int	j;

  k = 0;
  while (cmd->args[k] != NULL)
    {
      if (cmd->args[k][0] == '$' && cmd->args[k][1] != 0)
	{
	  if ((tp = malloc_str(sizeof(*tp) *
			       (utl_strlen(cmd->args[k]) + 1))) == NULL)
	    return;
	  i = 0;
	  j = 1;
	  while (cmd->args[k][j] != 0)
	    tp[i++] = cmd->args[k][j++];
	  tp[i] = 0;
	  args_modifier(cmd, tp, sys, k);
	  free(tp);
	}
      k++;
    }
}

int	builtin_launch(t_cmd *cmd, t_system *sys)
{
  if (cmd->path == NULL)
    return (launch_not_found(cmd));
  get_env_var(cmd, sys);
  check_if_wildcard(cmd, sys);
  if (execve(cmd->path, cmd->args, sys->env) == -1)
    return (launch_not_found(cmd));
  return (SIGRTN_NOERR);
}
