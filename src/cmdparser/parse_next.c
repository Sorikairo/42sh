/*
** parse_next.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 19 11:02:48 2014 Laurent Fourrier
** Last update Wed May 28 14:04:30 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tlist.h>
#include <tutils.h>
#include "cmdparser.h"
#include "builtin.h"

char	*get_current_cmd(char *cmd)
{
  char	in_quote;
  int	it;

  it = 0;
  in_quote = 0;
  while (cmd[it])
    {
      if (!in_quote && cmd[it] == COMMENT_CHAR)
	return (utl_strncpy(cmd, it));
      else if (cmd[it] == '"')
	in_quote = !in_quote;
      else if (cmd[it] == '\\' && cmd[it + 1] != '\0')
	it++;
      else if (get_sym(cmd + it) && !in_quote)
	return (utl_strncpy(cmd, it));
      it++;
    }
  return (utl_strcpy(cmd));
}

char	**array_cpy(char **array)
{
  char	**rtn;
  int	i;

  i = 0;
  rtn = malloc(sizeof(char *) * (get_wordarr_len(array) + 1));
  while (array[i] != NULL)
    {
      rtn[i] = utl_strcpy(array[i]);
      i++;
    }
  rtn[i] = NULL;
  return (rtn);
}

void	get_real_cmd(char **array, t_cmd *rtn, t_system *sys)
{
  char		*buf;
  char		**cmd_arr;
  int		i;
  int		it;

  i = 0;
  if (sys->alias != NULL)
    {
      destroy_wordarr(rtn->args);
      buf = get_matched_alias(array[0], sys->alias);
      cmd_arr = str_to_wordarr(buf, " \t");
      free(buf);
      rtn->args = malloc(sizeof(char *)
			* (get_wordarr_len(array) + get_wordarr_len(cmd_arr)));
      it = 0;
      while (cmd_arr[it])
	rtn->args[i++] = utl_strcpy(cmd_arr[it++]);
      destroy_wordarr(cmd_arr);
     it = 1;
     while (array[it])
       rtn->args[i++] = utl_strcpy(array[it++]);
     rtn->args[i] = NULL;
     free(rtn->cmd);
     rtn->cmd = (rtn->args[0]) ? utl_strcpy(rtn->args[0]) : NULL;
   }
}

t_cmd	*create_real_cmd(t_cmd *rtn, t_system *sys)
{
  char	**array_copy;
  int	i;

  i = 0;
  array_copy = array_cpy(rtn->args);
  get_real_cmd(array_copy, rtn, sys);
  if (!rtn->cmd)
    return (NULL);
  while (utl_strcmp(array_copy[0], rtn->args[0]) != 0 && i < 25)
    {
      destroy_wordarr(array_copy);
      array_copy = array_cpy(rtn->args);
      get_real_cmd(array_copy, rtn, sys);
      i++;
    }
  destroy_wordarr(array_copy);
  if (i == 25)
    {
      write_str(g_fstdout, "\nToo many alias loop");
      flush_file(g_fstdout);
      destroy_cmdlist(rtn);
      return (NULL);
    }
  return (rtn);
}

t_cmd	*cmd_parse_next(char *line, t_system *sys, int sym)
{
  char	*cmd;
  char	**cmd_arr;
  t_cmd	*rtn;

  if ((rtn = ts_malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  cmd = get_current_cmd(line);
  rtn->nxtsym = get_next_sym(line);
  cmd_arr = fmt_str_to_wordarr(cmd, " \t");
  if (cmd_arr[0] == NULL)
    {
      free(cmd);
      destroy_wordarr(cmd_arr);
      return (NULL);
    }
  rtn->cmd = utl_strcpy(cmd_arr[0]);
  rtn->args = cmd_arr;
  rtn->path = NULL;
  rtn->next = NULL;
  free(cmd);
  return ((sym >= SYM_REDIR_RGT && sym <= SYM_REDIR_OLFT) ? rtn :
	  create_real_cmd(rtn, sys));
}
