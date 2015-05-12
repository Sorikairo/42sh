/*
** xmalloc.c for 42sh in /home/fouhet_k/rendu/PSU_2013_minishell2/42sh/source
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Apr  7 10:15:39 2014 Kevin Fouhety
** Last update Sat May 24 11:25:35 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	<tutils.h>
#include	"my_printf.h"

char		*my_memset(char *str, char a, int size)
{
  int		i;

  i = 0;
  while (i != size)
    {
      str[i] = a;
      i++;
    }
  return (str);
}

char		*malloc_str(int size)
{
  char		*str;

  if ((str = malloc(size)) == NULL)
    return (NULL);
  str = my_memset(str, 0, size);
  return (str);
}

char		*realloc_and_cat(char *s1, char *s2)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (utl_strcpy("\0"));
  j = my_strlen(s1);
  if ((tmp = malloc_str(sizeof(*tmp) * (j + my_strlen(s2) + 1))) == NULL)
    return (utl_strcpy("\0"));
  while (s1[i] != '\0')
    {
      tmp[i] = s1[i];
      i++;
    }
  i = 0;
  while (s2[i] != '\0')
    tmp[j++] = s2[i++];
  tmp[j] = '\0';
  free(s1);
  if ((s1 = strdup(tmp)) == NULL)
    return (utl_strcpy("\0"));
  free(tmp);
  return (s1);
}
