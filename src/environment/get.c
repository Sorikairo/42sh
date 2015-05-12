/*
** get.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 22:20:09 2014 Laurent Fourrier
** Last update Sat Mar  8 20:19:38 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "environment.h"

int	env_get_addr(char **env, char *var)
{
  int	it;
  int	var_len;

  it = 0;
  var_len = utl_strlen(var);
  while (env[it] != NULL)
    {
      if (!utl_strncmp(var, env[it], var_len - 1) && env[it][var_len] == '=')
	return (it);
      it++;
    }
  return (-1);
}

char	*env_get(char **env, char *var)
{
  int	addr;

  addr = env_get_addr(env, var);
  return ((addr == -1) ? NULL : (env[addr] + utl_strlen(var) + 1));
}
