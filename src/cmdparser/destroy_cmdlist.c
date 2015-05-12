/*
** destroy_cmdlist.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 19 14:27:52 2014 Laurent Fourrier
** Last update Fri Feb 21 22:34:08 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "cmdparser.h"

void	destroy_cmdlist(t_cmd *list)
{
  t_cmd	*tmp;

  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->cmd);
      free(tmp->path);
      destroy_wordarr(tmp->args);
      free(tmp);
    }
}
