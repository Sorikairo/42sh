/*
** sort_word.c for sort_word in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat May  3 14:30:58 2014 Barneaud Viveka
** Last update Sat May 24 17:34:37 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	"autocompletion.h"

void		swap_str(char **s1, char **s2)
{
  char		*tmp;

  tmp = strdup(*s2);
  free(*s2);
  *s2 = strdup(*s1);
  free(*s1);
  *s1 = strdup(tmp);
  free(tmp);
}

void		free_lower(char *tmp1, char *tmp2)
{
  free(tmp1);
  free(tmp2);
}

int		sort_word(char **s1, char **s2)
{
  int		i;
  char		*tmp1;
  char		*tmp2;

  i = 0;
  tmp1 = lowerize(*s1);
  tmp2 = lowerize(*s2);
  while ((*s1)[i] != '\0' && (*s2)[i] != '\0')
    {
      if (tmp1[i] > tmp2[i])
	{
	  swap_str(s1, s2);
	  free_lower(tmp1, tmp2);
	  return (1);
	}
      else if (tmp1[i] == tmp2[i])
	i++;
      else
	{
	  free_lower(tmp1, tmp2);
	  return (0);
	}
    }
  free_lower(tmp1, tmp2);
  return (0);
}

char		**ord_alpha(char **wtab)
{
  int		sort;
  int		k;

  sort = 1;
  if (wtab == NULL)
    return (NULL);
  while (sort != 0)
    {
      sort = 0;
      k = 0;
      while (wtab[k] != NULL)
	{
	  if (wtab[k + 1] != NULL)
	    sort = sort + sort_word(&(wtab[k]), &(wtab[k + 1]));
	  k++;
	}
    }
  return (wtab);
}
