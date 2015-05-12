/*
** get_paths.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 19:29:40 2014 Laurent Fourrier
** Last update Sat May 24 11:22:26 2014 Barneaud Viveka
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>
#include <string.h>
#include "cmdparser.h"

char	*cmd_construct_path(char *cmd, char *path)
{
  char	*rtn;

  if (utl_strncmp(cmd, "./", 2) == 0)
    rtn = utl_strcpy(cmd);
  else
    {
      if ((rtn = ts_malloc(utl_strlen(cmd) + utl_strlen(path) + 2)) == NULL)
	return (utl_strcpy("\0"));
      rtn[0] = '\0';
      utl_strcat(rtn, path);
      utl_strcat(rtn, "/");
      utl_strcat(rtn, cmd);
    }
  return (rtn);
}

char	*cmd_get_path(char *cmd, char *path)
{
  char	*rtn;
  char	*cur_path;
  char	**path_arr;
  int	it;

  if (cmd[0] == '/')
    return (utl_strcpy(cmd));
  it = 0;
  rtn = NULL;
  path_arr = str_to_wordarr(path, ":");
  while (path_arr[it] != NULL)
    {
      cur_path = cmd_construct_path(cmd, path_arr[it]);
      if (access(cur_path, R_OK | X_OK) == 0)
	{
	  if (rtn)
	    free(rtn);
	  rtn = utl_strcpy(cur_path);
	}
      free(cur_path);
      it++;
    }
  destroy_wordarr(path_arr);
  return (rtn);
}

void	cmd_get_paths(t_cmd *cmd, char *path)
{
  while (cmd != NULL)
    {
      cmd->path = cmd_get_path(cmd->cmd, path);
      cmd = cmd->next;
    }
}
