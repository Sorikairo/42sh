/*
** chdir_newpath.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar  6 13:41:31 2014 Laurent Fourrier
** Last update Sat May 24 15:46:19 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>
#include "builtin.h"

int	chdir_nextlen(char *modifier)
{
  int	it;

  it = 0;
  while (modifier[it] != '\0' && modifier[it] != '/')
    it++;
  return (it);
}

char	*chdir_nextdir(char *modifier)
{
  char	*rtn;
  int	it;
  int	size;

  size = chdir_nextlen(modifier);
  it = 0;
  if ((rtn = ts_malloc(size + 1)) == NULL)
    return (NULL);
  while (it < size)
    {
      rtn[it] = modifier[it];
      it++;
    }
  rtn[it] = '\0';
  return (rtn);
}

char	*chdir_newpath(char *path, char *modifier)
{
  char	*nextdir;
  char	*newpath;

  if (*modifier == '/' || *modifier == '~')
    modifier++;
  while (*modifier)
    {
      if (*modifier == '/')
	modifier++;
      else if (utl_strncmp(modifier, "./", 2) == 0)
	modifier += 2;
      else
	{
	  nextdir = chdir_nextdir(modifier);
	  if (utl_strcmp(nextdir, "..") == 0)
	    newpath = chdir_parent(path);
	  else
	    newpath = chdir_enter(path, nextdir);
	  modifier += utl_strlen(nextdir);
	  free(nextdir);
	  free(path);
	  path = newpath;
	}
    }
  return (path);
}
