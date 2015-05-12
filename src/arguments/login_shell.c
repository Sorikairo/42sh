/*
** login_shell.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 21:33:30 2014 Laurent Fourrier
** Last update Tue May 13 15:49:54 2014 Laurent Fourrier
*/

#include "system.h"

int	arg_login_shell(int argc, char **argv, t_system *sys, t_shell *shell)
{
  shell->mode |= INTERACT_MASK;
  return (0);
}
