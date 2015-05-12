/*
** destroy_wordarr.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Dec  6 13:44:20 2013 Laurent Fourrier
** Last update Fri Feb 21 22:31:49 2014 Laurent Fourrier
*/

#include <stdlib.h>

void	destroy_wordarr(char **wordarr)
{
  int	it;

  it = 0;
  while (wordarr[it] != NULL)
    free(wordarr[it++]);
  free(wordarr);
}
