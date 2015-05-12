/*
** move_in_history.c for 42sh in /home/deffon_k/rendu/repo-42sh/src/line_edit
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Wed May  7 08:40:08 2014 deffontaine kevin
** Last update Fri May 16 10:46:01 2014 deffontaine kevin
*/

#include <tsys.h>
#include <tutils.h>
#include "line_editor.h"

char	*reprint_nextcmd(t_history *history, int pos)
{
  int		count;
  t_history	*tmp;
  t_history	*rtn;

  count = 0;
  tmp = history;
  rtn = history;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      count += 1;
    }
  while (rtn != NULL && count >= pos)
    {
      rtn = rtn->next;
      count -= 1;
    }
  return (rtn->cmd);
}

char	*reprint_lastcmd(t_history *history, int pos)
{
  int		count;
  t_history	*tmp;
  t_history	*rtn;

  count = 0;
  tmp = history;
  rtn = history;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      count += 1;
    }
  while (rtn != NULL && count >= pos)
    {
      rtn = rtn->next;
      count -= 1;
    }
  if (pos == 0)
    return ("\0");
  return (rtn->cmd);
}

int	size_list(t_history *history)
{
  t_history	*tmp;
  int	count;

  count = 0;
  tmp = history;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
      count += 1;
    }
  count = count + 1;
  return (count);
}

char	*reprint_cmd(char *buffer, t_system *av, char *nbuf)
{
  int	count;

  if (av->history != NULL)
    {
      if (buffer[2] == 65)
	{
	  count = size_list(av->history);
	  if (av->pos_in_history < count)
	    {
	      free(nbuf);
	      av->pos_in_history += 1;
	      nbuf = utl_strcpy(reprint_nextcmd(av->history, av->pos_in_history));
	    }
	}
      else if (buffer[2] == 66)
	{
	  if (av->pos_in_history > 0)
	    {
	      free(nbuf);
	      av->pos_in_history -= 1;
	      nbuf = utl_strcpy(reprint_lastcmd(av->history, av->pos_in_history));
	    }
	}
    }
  return (nbuf);
}
