/*
** create_path.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 18:18:13 2014 Laurent Fourrier
** Last update Fri Apr 25 18:20:00 2014 Laurent Fourrier
*/

#include <tsys.h>
#include <tutils.h>
#include "environment.h"

char	*create_path(char **env)
{
  char	*rtn;

  if ((rtn = env_get(env, "PATH")) == NULL)
    {
      if ((rtn = ts_malloc(1)) == NULL)
	return (NULL);
      rtn[0] = '\0';
      return (rtn);
    }
  return (utl_strcpy(rtn));
}
