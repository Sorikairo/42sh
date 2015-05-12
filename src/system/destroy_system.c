/*
** destroy_system.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May 23 04:53:45 2014 Laurent Fourrier
** Last update Fri May 23 05:00:49 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "system.h"
#include "builtin.h"

void	destroy_system(t_system *system)
{
  if (system->history)
    destroy_history(system);
  if (system->alias)
    destroy_alias(system->alias);
  destroy_wordarr(system->env);
}
