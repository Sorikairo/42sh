/*
** env.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 11:24:44 2014 Laurent Fourrier
** Last update Mon Mar  3 12:38:23 2014 Laurent Fourrier
*/

#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

int	builtin_env(t_cmd *cmd, t_system *sys)
{
  env_print(sys->env);
  return (SIGRTN_NOERR);
}
