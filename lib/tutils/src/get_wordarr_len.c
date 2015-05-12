/*
** get_wordarr_len.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Dec  6 13:45:27 2013 Laurent Fourrier
** Last update Fri Dec  6 20:16:59 2013 Laurent Fourrier
*/

#include <stdlib.h>

int	get_wordarr_len(char **wordarr)
{
  int	it;

  it = 0;
  while (wordarr[it] != NULL)
    it++;
  return (it);
}
