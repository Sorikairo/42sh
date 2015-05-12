/*
** chdir_buildbase.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar  6 13:56:19 2014 Laurent Fourrier
** Last update Thu Mar  6 14:08:29 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>
#include "environment.h"

char	*chdir_buildbase(char **env, char *path, char *modifier)
{
  char	*home;

  if (*modifier == '/')
    return (utl_strcpy("/"));
  if (*modifier == '~')
    {
      if ((home = env_get(env, "HOME")) == NULL)
	return (utl_strcpy("/home"));
      return (utl_strcpy(home));
    }
  return (utl_strcpy(path));
}
