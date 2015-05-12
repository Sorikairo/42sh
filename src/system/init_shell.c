/*
** init_shell.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue May  6 14:01:43 2014 Laurent Fourrier
** Last update Tue May 13 14:47:42 2014 Laurent Fourrier
*/

#include "system.h"

t_shell		init_shell()
{
  t_shell	rtn;

  rtn.mode = 0;
  rtn.mode |= INTERACT_MASK;
  return (rtn);
}
