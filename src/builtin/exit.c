/*
** exit.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 17:47:17 2014 Laurent Fourrier
** Last update Tue Feb 25 18:20:19 2014 Laurent Fourrier
*/

#include <tio.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

int	builtin_exit(t_cmd *cmd, t_system *sys)
{
  if (cmd->args[1] != NULL)
    {
      if (utl_strisnbr(cmd->args[1]))
	sys->last_rtn = utl_atoi(cmd->args[1]);
      else
	{
	  write_str(g_fstdout, "Warning: ");
	  write_str(g_fstdout, cmd->args[1]);
	  write_str(g_fstdout, " is not a number.\n");
	  flush_file(g_fstdout);
	  sys->last_rtn = 0;
	}
    }
  else
    sys->last_rtn = 0;
  return (SIGRTN_EXIT);
}
