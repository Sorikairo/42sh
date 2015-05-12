/*
** get_sym.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 19 12:59:22 2014 Laurent Fourrier
** Last update Thu May 22 19:14:58 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>
#include "cmdparser.h"

t_sym		g_sym[] =
  {
    {";", SYM_SEMICOLON, FALSE},
    {"||", SYM_BIN_OR, FALSE},
    {"|", SYM_PIPE, TRUE},
    {">>", SYM_REDIR_ORGT, TRUE},
    {"<<", SYM_REDIR_OLFT, TRUE},
    {">", SYM_REDIR_RGT, TRUE},
    {"<", SYM_REDIR_LFT, TRUE},
    {"&&", SYM_BIN_AND, FALSE},
    {NULL, SYM_NONE, FALSE}
  };

static char	str_begins_with(char *str, char *cmp)
{
  int		len;

  len = utl_strlen(cmp);
  return (!utl_strncmp(str, cmp, len));
}

int		get_sym(char *str)
{
  int		it;

  it = 0;
  while (g_sym[it].sym)
    {
      if (str_begins_with(str, g_sym[it].str))
	return (g_sym[it].sym);
      it++;
    }
  return (SYM_NONE);
}

t_bool		is_chainloadable(int sym)
{
  int		it;

  it = 0;
  while (g_sym[it].sym)
    {
      if (g_sym[it].sym == sym)
	return (g_sym[it].chain);
      it++;
    }
  return (g_sym[it].chain);
}

char	*skip_sym(char *str)
{
  int		it;

  it = 0;
  while (g_sym[it].sym)
    {
      if (str_begins_with(str, g_sym[it].str))
	return (str + utl_strlen(g_sym[it].str));
      it++;
    }
  return (str);
}
