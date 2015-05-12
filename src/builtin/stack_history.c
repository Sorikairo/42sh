/*
** stack_history.c for minishell2 in /home/deffon_k/rendu/repo-42sh/src/builtin
** 
** Made by deffontaine kevin
** Login   <deffon_k@epitech.net>
** 
** Started on  Fri Apr 11 12:39:06 2014 deffontaine kevin
** Last update Thu May 22 13:08:34 2014 deffontaine kevin
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include "tutils.h"
#include "line_editor.h"
#include "builtin.h"
#include "tutils.h"
#include "tio.h"
#include "environment.h"

t_history	*stack_history(t_history *history, char *line)
{
  t_history	*elem;
  t_history	*tmp;
  char		*temp;

  if ((elem = malloc(sizeof(*history))) == NULL)
    return (NULL);
  temp = utl_strcpy(line);
  elem->cmd = temp;
  elem->next = NULL;
  if (history == NULL)
    return (elem);
  tmp = history;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  return (history);
}

void		write_history(t_system *av)
{
  t_history	*tmp;
  t_file	*file;
  char		*path;

  if ((path = env_get(av->env, "HOME")) != NULL)
    {
      path = utl_strcpy(path);
      path = ts_realloc(path, utl_strlen(path) + 1, utl_strlen(path) + 16);
      path = utl_strcat(path, "/.bash_history");
      if ((file = open_file(path, FILE_W)) != NULL)
  	{
	  tmp = av->history;
  	  while (tmp != NULL)
  	    {
  	      write_str(file, tmp->cmd);
	      if (tmp->next != NULL)
		write_char(file, '\n');
  	      tmp = tmp->next;
  	    }
  	  flush_file(file);
  	  close_file(file);
  	  free(path);
  	}
    }
}

void	destroy_history(t_system *av)
{
  t_history	*tmp;

  write_history(av);
  while (av->history != NULL)
    {
      tmp = av->history;
      av->history = av->history->next;
      free(tmp->cmd);
      free(tmp);
    }
}
