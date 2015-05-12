/*
** unalias.c for 42sh in /home/cruvei_t/rendu/repo-42sh/src/builtin
** 
** Made by CRUVEILHER Thomas
** Login   <cruvei_t@epitech.net>
** 
** Started on  Thu Apr 24 16:53:06 2014 CRUVEILHER Thomas
** Last update Sat May 24 17:59:17 2014 Barneaud Viveka
*/

#include <tio.h>
#include <tutils.h>
#include <tsys.h>
#include "cmdparser.h"
#include "builtin.h"

static int	unalias_error()
{
  write_str(g_fstdout, "unalias : usage : unalias [-a] name\n");
  flush_file(g_fstdout);
  return (SIGRTN_NOERR);
}

static void	remove_an_alias(t_alias **alias)
{
  if ((*alias)->next != NULL && (*alias)->previous != NULL)
    {
      (*alias)->previous->next = (*alias)->next;
      (*alias)->next->previous = (*alias)->previous;
      (*alias) = (*alias)->previous;
    }
  else if ((*alias)->next != NULL && (*alias)->previous == NULL)
    {
      (*alias)->next->previous = NULL;
      (*alias) = (*alias)->next;
    }
  else if ((*alias)->next == NULL && (*alias)->previous != NULL)
    {
      (*alias)->previous->next = NULL;
      (*alias) = (*alias)->previous;
    }
  else
    (*alias) = NULL;
}

static int	unalias_remove_all(t_alias **alias)
{
  while (*alias != NULL)
    remove_an_alias(alias);
  return (0);
}

static int	unalias_one(t_alias **alias, char *alias_to_remov)
{
  t_alias *tmp;

  tmp = *alias;
  while (tmp != NULL && utl_strcmp(tmp->nickname, alias_to_remov) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (unalias_error());
  remove_an_alias(alias);
  return (0);
}

int	builtin_unalias(t_cmd *cmd, t_system *sys)
{
  if (get_wordarr_len(cmd->args) != 2)
    return (unalias_error());
  if (utl_strcmp(cmd->args[1], "-a") == 0)
    return (unalias_remove_all(&(sys->alias)));
  return (unalias_one(&(sys->alias), cmd->args[1]));
}
