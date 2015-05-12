/*
** parse.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb  4 11:14:31 2014 Laurent Fourrier
** Last update Wed May 28 13:55:26 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include <string.h>
#include "cmdparser.h"

static t_cmd	*put_syntax_error(t_cmd *to_free)
{
  write_str(g_fstdout, "\nError: syntax error");
  flush_file(g_fstdout);
  destroy_cmdlist(to_free);
  return (NULL);
}

t_cmd		*push_cmd(t_cmd *cur, t_cmd *cmd, int sym)
{
  t_cmd		*tmp;

  if (cur == NULL)
    return (cmd);
  tmp = cur;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = cmd;
  if (sym >= 0)
    tmp->nxtsym = sym;
  return (cur);
}

char		*cmd_skip(char *line)
{
  char		in_quote;

  in_quote = 0;
  while (*line)
    {
      if (!in_quote && *line == COMMENT_CHAR)
	return (line);
      else if (*line == '"')
	in_quote = !in_quote;
      else if (line[0] == '\\' && line[1] != '\0')
	line++;
      else if (get_sym(line) && !in_quote)
	return (skip_sym(line));
      line++;
    }
  return (line);
}

static t_cmd	*cmd_parse_short(char *line, t_system *sys,
				 int sym, char **next)
{
  char		*save;
  t_cmd		*rtn;
  t_cmd		*tmp;

  if ((save = fmt_get_next_word(line, " \t", &line)) == NULL ||
      (tmp = ts_malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  if ((rtn = cmd_parse_next(line, sys, SYM_NONE)) == NULL)
    {
      tmp->nxtsym = get_next_sym(line);
      line = cmd_skip(line);
      if ((tmp->nxtsym < SYM_REDIR_RGT || tmp->nxtsym > SYM_REDIR_OLFT) ||
	  (rtn = cmd_parse_short(line, sys, tmp->nxtsym, &line)) == NULL)
	return (NULL);
    }
  tmp->cmd = save;
  tmp->path = NULL;
  tmp->args = str_to_wordarr(save, "");
  tmp->nxtsym = get_lastcmd(rtn)->nxtsym;
  tmp->next = NULL;
  push_cmd(rtn, tmp, sym);
  *next = line;
  return (rtn);
}

t_cmd		*cmd_parse(char *line, t_system *sys)
{
  int		sym;
  t_cmd		*rtn;
  t_cmd		*to_add;

  rtn = NULL;
  sym = SYM_NONE;
  while (line && *line && *line != COMMENT_CHAR)
    {
      to_add = cmd_parse_next(line, sys, sym);
      sym = get_next_sym(line);
      line = cmd_skip(line);
      if (to_add != NULL)
	rtn = push_cmd(rtn, to_add, -1);
      else if (sym >= SYM_REDIR_RGT && sym <= SYM_REDIR_OLFT)
	{
	  if ((to_add = cmd_parse_short(line, sys, sym, &line)) == NULL)
	    return (put_syntax_error(rtn));
	  rtn = push_cmd(rtn, to_add, -1);
	  line = cmd_skip(line);
	  sym = SYM_NONE;
	}
      else if (rtn)
	return (put_syntax_error(rtn));
    }
  return ((sym == SYM_NONE) ? rtn : put_syntax_error(rtn));
}
