/*
** set.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 18:34:55 2014 Laurent Fourrier
** Last update Sat May 24 11:22:46 2014 Barneaud Viveka
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include <string.h>
#include "prompt.h"
#include "environment.h"

char	*env_generate_var(char *var, char *value)
{
  char	*rtn;

  if ((rtn = ts_malloc(utl_strlen(var) + utl_strlen(value) + 2)) == NULL)
    return (utl_strcpy("\0"));
  rtn[0] = '\0';
  utl_strcat(rtn, var);
  utl_strcat(rtn, "=");
  utl_strcat(rtn, value);
  return (rtn);
}

char	**env_create_var(char **env, char *var, char *value)
{
  int	env_size;

  env_size = get_wordarr_len(env);
  if ((env = ts_realloc(env, (env_size + 1) * sizeof(void*),
			(env_size + 2) * sizeof(void*))) == NULL)
    return (NULL);
  env[env_size] = env_generate_var(var, value);
  env[env_size + 1] = NULL;
  return (env);
}

char	**env_set(char **env, char *var, char *value)
{
  int	addr;

  if (utl_strcmp(var, "PWD") == 0)
    {
      if (access(value, R_OK) == -1 || chdir(value) == -1)
	{
	  write_str(g_fstdout, "Error: PWD is not a placeholder for");
	  write_str(g_fstdout, " garbage. Get your shit together!\n");
	  flush_file(g_fstdout);
	  return (env);
	}
    }
  else if (utl_strcmp(var, "PS1") == 0)
    {
      free(g_prompt.format);
      g_prompt.format = utl_strcpy(value);
    }
  if ((addr = env_get_addr(env, var)) == -1)
    return (env_create_var(env, var, value));
  free(env[addr]);
  env[addr] = env_generate_var(var, value);
  return (env);
}
