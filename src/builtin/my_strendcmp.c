/*
** my_strendcmp.c for my_strendcmp in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Mon May 19 13:59:00 2014 Barneaud Viveka
** Last update Sat May 24 11:40:31 2014 Barneaud Viveka
*/

#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>
#include	<tutils.h>
#include	"autocompletion.h"

int		my_strendcmp(char *s1, char *s2)
{
  int		i;
  int		j;

  if (utl_strlen(s2) < utl_strlen(s1))
    return (1);
  i = 0;
  j = utl_strlen(s2) - utl_strlen(s1);
  while (s2[j] != 0 && s1[i] != 0)
    {
      if (s1[i] != s2[j])
	return (1);
      j++;
      i++;
    }
  return (0);
}

char		**add_files_to_args(char **args, char **files, int pos)
{
  char		**ret;
  int		k;
  int		l;

  if ((ret = malloc(sizeof(*ret) *
		    (count_slot(args) + count_slot(files) + 1))) == NULL)
    return (args);
  k = 0;
  while (k != pos && args[k] != NULL)
    {
      ret[k] = args[k];
      k++;
    }
  l = 0;
  while (files[l] != NULL)
    ret[k++] = files[l++];
  l = pos + 1;
  while (args[l] != NULL)
    ret[k++] = args[l++];
  ret[k] = NULL;
  return (ret);
}
