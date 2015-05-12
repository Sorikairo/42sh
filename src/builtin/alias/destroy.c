/*
** destroy.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May 23 04:58:14 2014 Laurent Fourrier
** Last update Fri May 23 05:01:36 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"

void		destroy_alias(t_alias *alias)
{
  t_alias	*next;

  while (alias)
    {
      next = alias->next;
      free(alias->nickname);
      destroy_wordarr(alias->args);
      free(alias);
      alias = next;
    }
}
