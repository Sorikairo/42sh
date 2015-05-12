/*
** init.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 18:48:38 2014 Laurent Fourrier
** Last update Wed May 21 13:00:08 2014 deffontaine kevin
*/

#include <tsys.h>
#include <stdlib.h>
#include "system.h"
#include "environment.h"
#include "builtin.h"
#include "tio.h"
#include "tutils.h"

void		fill_history(t_system *av)
{
  t_file	*file;
  char		*path;
  char		*line;

  if ((path = env_get(av->env, "HOME")) != NULL)
    {
      path = utl_strcpy(path);
      path = ts_realloc(path, utl_strlen(path) + 1, utl_strlen(path) + 16);
      path = utl_strcat(path, "/.bash_history");
      if ((file = open_file(path, FILE_R)) != NULL)
	{
	  while ((line = read_line(file)) != NULL)
	    {
	      av->history = stack_history(av->history, line);
	      free(line);
	    }
	  close_file(file);
	  free(path);
	}
    }
}

t_system	init_system(char **env)
{
  t_system	rtn;

  rtn.env = env_check(env);
  rtn.quit = 0;
  rtn.wait = 1;
  rtn.promp = 1;
  rtn.last_rtn = 0;
  rtn.child_pid = 0;
  rtn.history = NULL;
  rtn.alias = NULL;
  return (rtn);
}
