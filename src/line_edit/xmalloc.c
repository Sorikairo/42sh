/*
** xmalloc.c for 42sh in /home/fouhet_k/rendu/PSU_2013_minishell2/42sh/source
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Apr  7 10:15:39 2014 Kevin Fouhety
** Last update Mon Apr  7 10:16:04 2014 Kevin Fouhety
*/

#include "line_editor.h"

char    *xmalloc(int i)
{
  char  *ret;

  if ((ret = malloc(i * sizeof (char *))) == NULL)
    return (NULL);
  return (ret);
}
