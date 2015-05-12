/*
** chdir_enter.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar  5 14:42:19 2014 Laurent Fourrier
** Last update Sat May 24 15:46:58 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>

int	chdir_has_dirsep(char *path)
{
  while (*path)
    {
      if (path[0] == '/' && path[1] == '\0')
	return (1);
      path++;
    }
  return (0);
}

char	*chdir_enter(char *path, char *next)
{
  char	*rtn;

  if ((rtn = ts_malloc(utl_strlen(path) + utl_strlen(next) + 2)) == NULL)
    return (NULL);
  rtn[0] = '\0';
  utl_strcat(rtn, path);
  if (!chdir_has_dirsep(rtn))
    utl_strcat(rtn, "/");
  utl_strcat(rtn, next);
  return (rtn);
}
