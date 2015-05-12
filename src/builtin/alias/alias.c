/*
** alias.c for 42sh in /home/cruvei_t/rendu/repo-42sh/src/cmdparser
** 
** Made by CRUVEILHER Thomas
** Login   <cruvei_t@epitech.net>
** 
** Started on  Wed Apr 23 15:01:16 2014 CRUVEILHER Thomas
** Last update Sun May 25 14:44:52 2014 
*/

#include <stdlib.h>
#include <tutils.h>
#include <tio.h>
#include <tsys.h>
#include "cmdparser.h"
#include "builtin.h"

static int	alias_error()
{
  write_str(g_fstdout, "Syntax : alias [alias]=[cmd]\n");
  flush_file(g_fstdout);
  return (SIGRTN_NOERR);
}

static int	alias_add_alias(t_alias **alias, char *cmd)
{
  t_alias	*tmp;
  char		**final_alias;

  if ((tmp = ts_malloc(sizeof(t_alias))) == NULL ||
      (final_alias = ts_malloc(sizeof(t_alias))) == NULL)
    return (-1);
  final_alias[0] = get_next_word(cmd, "=", &final_alias[1]);
  if (final_alias[1][0] == '\0')
    return (alias_error());
  final_alias[2] = NULL;
  tmp->args = fmt_str_to_wordarr(final_alias[1], " \t");
  tmp->nickname = utl_strcpy(final_alias[0]);
  tmp->next = *alias;
  tmp->previous = NULL;
  if (tmp->next != NULL)
    tmp->next->previous = tmp;
  *alias = tmp;
  free(final_alias[0]);
  free(final_alias);
  return (0);
}

int		alias_print(t_alias **alias)
{
  t_alias	*tmp;
  int		i;

  tmp = *alias;
  while (tmp != NULL)
    {
      i = 1;
      write_str(g_fstdout, tmp->nickname);
      write_str(g_fstdout, "=");
      write_str(g_fstdout, "'");
      if (tmp->args[0] != NULL)
	write_str(g_fstdout, tmp->args[0]);
      if (get_wordarr_len(tmp->args) > 1)
	while (tmp->args[i] != NULL)
	  {
	    write_str(g_fstdout, " ");
	    write_str(g_fstdout, tmp->args[i++]);
	  }
      write_str(g_fstdout, "'\n");
      tmp = tmp->next;
    }
  flush_file(g_fstdout);
  return (0);
}

int		builtin_alias(t_cmd *cmd, t_system *sys)
{
  if (get_wordarr_len(cmd->args) == 1)
    return (alias_print(&(sys->alias)));
  if (get_wordarr_len(cmd->args) != 2)
    return (alias_error());
  return (alias_add_alias(&(sys->alias), cmd->args[1]));
}

char		*get_matched_alias(char *cmd, t_alias *alias)
{
  char		*final_cmd;
  int		i;

  i = 1;
  while (alias)
    {
      if (utl_strcmp(cmd, (alias)->nickname) == 0)
	if (alias->args[0] != NULL)
	  {
	    final_cmd = utl_strcpy(alias->args[0]);
	    while (alias->args[i] != NULL)
	      {
		  final_cmd = ts_realloc(final_cmd, utl_strlen(final_cmd) + 1,
					 utl_strlen(final_cmd) + 2
					 + utl_strlen(alias->args[i]));
		  final_cmd = utl_strcat(final_cmd, " ");
		  final_cmd = utl_strcat(final_cmd, alias->args[i]);
		  i++;
	      }
	    return (final_cmd);
	  }
      (alias) = (alias)->next;
    }
  return (utl_strcpy(cmd));
}
