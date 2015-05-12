/*
** get_next_sym.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May 22 21:45:50 2014 Laurent Fourrier
** Last update Thu May 22 21:47:22 2014 Laurent Fourrier
*/

#include "cmdparser.h"

int	get_next_sym(char *cmd)
{
  char	in_quote;
  int	rtn;

  in_quote = 0;
  while (*cmd)
    {
      if (!in_quote && *cmd == COMMENT_CHAR)
	return (SYM_NONE);
      else if (*cmd == '"')
	in_quote = !in_quote;
      else if (cmd[0] == '\\' && cmd[1] != '\0')
	cmd++;
      else if ((rtn = get_sym(cmd)) != SYM_NONE && !in_quote)
	return (rtn);
      cmd++;
    }
  return (SYM_NONE);
}
