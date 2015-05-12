/*
** parsevar.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 18 15:59:25 2014 Laurent Fourrier
** Last update Wed May  7 10:55:37 2014 deffontaine kevin
*/

#include <stdlib.h>
#include <tutils.h>
#include "system.h"
#include "environment.h"

char	*env_parsevar(char **env, char *str)
{
  char	*var;
  char	*rtn;

  if (*str != VARIABLE_CHAR)
    return (str);
  var = get_next_word(str, VARIABLE_SEPS, NULL);
  if (!var)
    return ("undefined");
  rtn = env_get(env, var);
  free(var);
  if (!rtn)
    return ("undefined");
  return (rtn);
}
