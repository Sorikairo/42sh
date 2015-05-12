/*
** open_fstd.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb  5 15:30:15 2014 Laurent Fourrier
** Last update Thu Feb  6 13:23:23 2014 Laurent Fourrier
*/

#include "tio.h"

void	open_fstd()
{
  g_fstdin = fd_open_file(0, FILE_R | FILE_NOPREREAD);
  g_fstdout = fd_open_file(1, FILE_W);
  g_fstderr = fd_open_file(2, FILE_W);
}
