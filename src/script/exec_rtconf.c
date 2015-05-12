/*
** exec_rtconf.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr 23 15:56:13 2014 Laurent Fourrier
** Last update Thu May  1 13:40:48 2014 deffontaine kevin
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "script.h"
#include "environment.h"

static char	*get_rc_path(t_system *system)
{
  char		*rtn;
  char		*home;

  home = env_get(system->env, "HOME");
  if (home)
    {
      rtn = ts_malloc(utl_strlen(home) + utl_strlen("/.swagrc") + 1);
      if (!rtn)
	return (NULL);
      rtn[0] = '\0';
      utl_strcat(rtn, home);
      utl_strcat(rtn, "/.swagrc");
      return (rtn);
    }
  return (NULL);
}

void		exec_rtconf(t_system *system)
{
  char		*path;
  t_file	*rcfile;

  path = get_rc_path(system);
  if (path)
    {
      if (access(path, R_OK) == 0)
	{
	  rcfile = open_file(path, FILE_R);
	  launch_script(rcfile, system);
	  close_file(rcfile);
	}
      free(path);
    }
}
