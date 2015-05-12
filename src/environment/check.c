/*
** check.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 22:23:28 2014 Laurent Fourrier
** Last update Sun May 25 04:26:42 2014 Kevin Fouhety
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include "environment.h"
#include "line_editor.h"

char	**env_check(char **env)
{
  if (env == NULL || *env == NULL)
    {
      if ((env = ts_malloc(sizeof(void*))) == NULL)
	return (NULL);
      *env = NULL;
    }
  return (env_cpy(env));
}
