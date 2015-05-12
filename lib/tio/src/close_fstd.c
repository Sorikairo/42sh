/*
** close_fstd.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb 13 11:59:15 2014 Laurent Fourrier
** Last update Thu Feb 13 12:00:11 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tio.h"

void	close_fstd()
{
  free(g_fstdin);
  free(g_fstdout);
  free(g_fstderr);
}
