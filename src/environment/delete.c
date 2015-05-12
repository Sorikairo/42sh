/*
** delete.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 20:33:35 2014 Laurent Fourrier
** Last update Thu May 22 13:10:49 2014 Barneaud Viveka
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>
#include <string.h>
#include "environment.h"

char	**env_delete(char **env, char *var)
{
  char	**rtn;
  int	rtn_it;
  int	env_it;
  int	rm_addr;

  if ((rm_addr = env_get_addr(env, var)) == -1)
    return (env);
  if ((rtn = ts_malloc(get_wordarr_len(env) * sizeof(void*))) == NULL)
    return (NULL);
  rtn_it = 0;
  env_it = 0;
  while (env[env_it] != NULL)
    {
      if (env_it == rm_addr)
	free(env[env_it]);
      else
	rtn[rtn_it++] = env[env_it];
      env_it++;
    }
  rtn[rtn_it] = NULL;
  free(env);
  return (rtn);
}
