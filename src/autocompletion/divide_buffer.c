/*
** divide_buffer.c for divide_buffer in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 13:03:40 2014 Barneaud Viveka
** Last update Wed May 28 10:24:53 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	<tutils.h>
#include	"line_editor.h"
#include	"autocompletion.h"

char		*str_before_cursor(char *n, t_system *av)
{
  char		*current;
  int		i;

  i = 0;
  if (n == NULL || n[0] == '\0')
    return (NULL);
  if ((current = malloc_str(sizeof(*current) * (utl_strlen(n) + 1))) == NULL)
    return (NULL);
  while (n[i] != '\0' && i <= g_pos)
    {
      current[i] = n[i];
      i++;
    }
  current[i] = '\0';
  return (current);
}

char		*str_after_cursor(char *nbuf, t_system *av)
{
  char		*aft;
  int		i;
  int		j;

  i = 0;
  if (nbuf == NULL || nbuf[0] == '\0')
    return (NULL);
  if ((aft = malloc_str(sizeof(*aft) * (utl_strlen(nbuf) + 1))) == NULL)
    return (NULL);
  while (i <= g_pos && nbuf[i] != '\0')
    i++;
  j = 0;
  while (nbuf[i] != '\0')
    aft[j++] = nbuf[i++];
  aft[j] = '\0';
  return (aft);
}

char		*current_word(char *bc)
{
  char		*current;
  char		**wtab;
  int		k;

  if (bc == NULL)
    return (NULL);
  wtab = my_str_to_wtab(bc, " ");
  if (wtab == NULL)
    return (utl_strcpy("\0"));
  k = count_slot(wtab) - 1;
  current = strdup(wtab[k]);
  if (current == NULL)
    return (utl_strcpy("\0"));
  free_wtab(wtab);
  return (current);
}

char		*get_file_path(char *cur, char **env)
{
  int		i;
  int		s;
  int		j;
  char		*ph;

  if (cur == NULL ||
      (ph = malloc_str(sizeof(*ph) * (utl_strlen(cur) + 1))) == NULL)
    return (utl_strcpy("\0"));
  i = 0;
  s = 0;
  if (utl_strlen(cur) >= 2 && cur[0] == '~' && cur[1] == '/')
    ph = get_home_and_realloc(env, sizeof(*ph) * (utl_strlen(cur) + 1), &i);
  j = utl_strlen(ph);
  while (cur[i] != '\0' && s != count_slash(cur))
    {
      if (cur[i] == '/')
	s++;
      ph[j++] = cur[i++];
    }
  ph[j] = '\0';
  if (ph[0] == '\0')
    ph = utl_strcpy(".");
  return (ph);
}

char		*get_start(char *cur)
{
  int		i;
  int		s;
  int		j;
  char		*start;

  i = 0;
  s = 0;
  j = 0;
  if (cur == NULL)
    return (utl_strcpy("\0"));
  while (cur[j] != '\0' && s != count_slash(cur))
    {
      if (cur[j] == '/')
	s++;
      j++;
    }
  if ((start = malloc_str(sizeof(*start) * (utl_strlen(cur) + 1))) == NULL)
    return (utl_strcpy("\0"));
  while (cur[j] != '\0')
    start[i++] = cur[j++];
  start[i] = '\0';
  return (start);
}
