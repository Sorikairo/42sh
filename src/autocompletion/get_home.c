/*
** get_home.c for get_home in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Thu May 22 13:02:19 2014 Barneaud Viveka
** Last update Wed May 28 10:25:05 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<tutils.h>
#include	"autocompletion.h"

char		*get_home_and_realloc(char **env, int size, int *count)
{
  char		*home;
  int		k;
  int		i;
  int		j;

  k = 0;
  while (env[k] != NULL)
    {
      i = 0;
      j = 5;
      if (strncmp(env[k], "HOME=", 5) == 0)
	{
	  if ((home = malloc_str(sizeof(*home) * utl_strlen(env[k]))) == NULL)
	    return (utl_strcpy("\0"));
	  while (env[k][j] != 0)
	    home[i++] = env[k][j++];
	  home[i] = 0;
	}
      k++;
    }
  home = realloc(home, utl_strlen(home) + size + 1);
  if (home == NULL)
    return (utl_strcpy("\0"));
  (*count)++;
  return (home);
}
