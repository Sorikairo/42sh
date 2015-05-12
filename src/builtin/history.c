/*
** history.c for history in /home/deffon_k/rendu/repo-42sh/src/builtin
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Tue May 13 12:03:35 2014 deffontaine kevin
** Last update Tue May 13 14:49:50 2014 deffontaine kevin
*/

#include <tutils.h>
#include "builtin.h"
#include "my_printf.h"

void		print_error()
{
  my_printf("bash: history: -d: option requires an argument\n");
  my_printf("history: usage: history [-c] [-d offset] [n] or");
  my_printf(" history -anrw [filenale] or history -ps arg [arg...]\n");
}

int		check_remove_args(t_cmd *cmd)
{
  int		count;
  int		test;

  test = 0;
  count = 0;
  while (cmd->args[2][count] != '\0')
    {
      if (cmd->args[2][count] < '0' || cmd->args[2][count] > '9')
	{
	  print_error();
	  test = 1;
	  return (test);
	}
      count++;
    }
  return (test);
}

void		remove_item(t_cmd *cmd, t_system *sys)
{
  int		test;
  int		rtn;
  int		count;
  t_history	*tmp;

  count = 0;
  test = 0;
  if (cmd->args[2] == NULL)
    print_error();
  else
    {
      test = check_remove_args(cmd);
      if (test == 0)
	{
	  rtn = utl_atoi(cmd->args[2]);
	  while (sys->history != NULL && count < rtn)
	    {
	      tmp = sys->history;
	      sys->history = sys->history->next;
	      count = count + 1;
	    }
	  if (count == rtn)
	    free(tmp->cmd);
	}
    }
}

int		builtin_history(t_cmd *cmd, t_system *sys)
{
  t_history	*tmp;

  if (cmd->args[1] == NULL)
    {
      tmp = sys->history;
      while (tmp->next != NULL)
	{
	  my_printf("%s\n", tmp->cmd);
	  tmp = tmp->next;
	}
    }
  else if (utl_strcmp(cmd->args[1], "-c") == 0)
    {
      while (sys->history != NULL)
	{
	  tmp = sys->history;
	  sys->history = sys->history->next;
	  free(tmp->cmd);
	}
    }
  else if (utl_strcmp(cmd->args[1], "-d") == 0)
    remove_item(cmd, sys);
  return (0);
}
