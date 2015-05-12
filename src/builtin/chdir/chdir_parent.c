/*
** chdir_parent.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar  5 14:31:57 2014 Laurent Fourrier
** Last update Sat May 24 15:46:44 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>

int	chdir_parent_len(char *path)
{
  int	it;
  int	rtn;

  it = 0;
  rtn = 1;
  while (path[it])
    {
      if (path[it] == '/' && path[it + 1] != '\0')
	rtn = it;
      it++;
    }
  return (rtn);
}

char	*chdir_parent(char *path)
{
  char	*rtn;
  int	it;
  int	size;

  size = chdir_parent_len(path);
  if ((rtn = ts_malloc(size + 2)) == NULL)
    return (NULL);
  it = 0;
  while (it <= size)
    {
      rtn[it] = path[it];
      it++;
    }
  rtn[it] = '\0';
  return (rtn);
}
