/*
** remove_nxtcmd.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May 23 01:14:34 2014 Laurent Fourrier
** Last update Fri May 23 01:25:43 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "cmdparser.h"

void	remove_nxtcmd(t_cmd *cmd)
{
  t_cmd	*tmp;

  tmp = cmd->next;
  if (tmp)
    {
      cmd->next = tmp->next;
      cmd->nxtsym = tmp->nxtsym;
      free(tmp->cmd);
      free(tmp->path);
      destroy_wordarr(tmp->args);
      free(tmp);
    }
}
