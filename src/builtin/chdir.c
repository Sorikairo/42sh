/*
** chdir.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar  4 17:50:34 2014 Laurent Fourrier
** Last update Sat Mar  8 20:21:17 2014 Laurent Fourrier
*/

#include <unistd.h>
#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

int	chdir_reterr(char *msg)
{
  write_str(g_fstdout, msg);
  flush_file(g_fstdout);
  return (SIGRTN_NOERR);
}

int	chdir_check(char *path)
{
  int	rtn;

  rtn = 0;
  if (access(path, F_OK) == -1)
    write_str(g_fstdout, "Error: cd: no such file or directory\n");
  else if (access(path, R_OK) == -1)
    write_str(g_fstdout, "Error: cd: you don't have the needed rights\n");
  else if (chdir(path) == -1)
    write_str(g_fstdout, "Error: cd: target isn't a directory\n");
  else
    rtn = 1;
  return (rtn);
}

int	builtin_chdir(t_cmd *cmd, t_system *sys)
{
  char	*pwd;
  char	*new_pwd;
  int	argc;

  argc = get_wordarr_len(cmd->args);
  if (argc > 1 && utl_strcmp(cmd->args[1], "-") == 0)
    chdir_oldpwd(sys);
  else if ((pwd = env_get(sys->env, "PWD")) == NULL)
    write_str(g_fstdout, "Error: cd: no current directory. Try setting PWD\n");
  else
    {
      new_pwd = ((argc < 2) ? chdir_buildbase(sys->env, pwd, "~") :
		 chdir_newpath(chdir_buildbase(sys->env, pwd, cmd->args[1]),
			       cmd->args[1]));
      if (chdir_check(new_pwd))
	{
	  sys->env = env_set(sys->env, "OLDPWD", pwd);
	  sys->env = env_set(sys->env, "PWD", new_pwd);
	}
      free(new_pwd);
    }
  flush_file(g_fstdout);
  return (SIGRTN_NOERR);
}
