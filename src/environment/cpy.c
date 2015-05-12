/*
** cpy.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 18:54:36 2014 Laurent Fourrier
** Last update Thu May 22 12:51:31 2014 Barneaud Viveka
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>

char	**env_cpy(char **env)
{
  char	**rtn;
  int	it;
  int	env_size;

  env_size = get_wordarr_len(env);
  if ((rtn = ts_malloc((env_size + 1) * sizeof(void*))) == NULL)
    return (NULL);
  it = 0;
  while (it < env_size)
    {
      rtn[it] = utl_strcpy(env[it]);
      it++;
    }
  rtn[it] = NULL;
  return (rtn);
}
