/*
** oldpwd.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar  8 16:46:54 2014 Laurent Fourrier
** Last update Fri May 23 16:03:20 2014 Barneaud Viveka
*/

#include <unistd.h>
#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "environment.h"

void	chdir_oldpwd(t_system *sys)
{
  char	*oldpwd;
  char	*pwd;

  if ((pwd = env_get(sys->env, "PWD")) == NULL)
    {
      write_str(g_fstdout, "Error: not allowed to get PWD variable in");
      write_str(g_fstdout, " the alpha and beta world lines.\nTry to run it");
      write_str(g_fstdout, " in the Steins;Gate instead.\n");
    }
  else if ((oldpwd = env_get(sys->env, "OLDPWD")) == NULL)
    write_str(g_fstdout, "Error: OLDPWD is not set\n");
  else if (chdir(oldpwd) != -1)
    {
      oldpwd = utl_strcpy(oldpwd);
      sys->env = env_set(sys->env, "OLDPWD", pwd);
      sys->env = env_set(sys->env, "PWD", oldpwd);
      free(oldpwd);
    }
}
