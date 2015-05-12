/*
** launch_binary.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May 22 13:58:14 2014 Laurent Fourrier
** Last update Fri May 23 01:17:41 2014 Laurent Fourrier
*/

#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

/*
** Properly sets the cmd->next and cmd->nxtsym with logical operators
*/
static void	binary_nxtcmd(t_cmd *cmd, int status)
{
  int		loop;

  loop = 1;
  while (loop)
    {
      if (cmd->nxtsym == SYM_BIN_AND)
	loop = !status;
      else if (cmd->nxtsym == SYM_BIN_OR)
	loop = status;
      else
	loop = 0;
      status = 0;
      if (loop)
	remove_nxtcmd(cmd);
    }
}

int		launch_binary(t_cmd *cmd, t_system *sys)
{
  int		nxtsym;

  nxtsym = cmd->nxtsym;
  cmd->nxtsym = 0;
  launch_cmd(cmd, sys);
  cmd->nxtsym = nxtsym;
  binary_nxtcmd(cmd, !sys->last_rtn);
  return (SIGRTN_NOERR);
}
