/*
** cp_paste.c for cp_paste in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 14:12:07 2014 Barneaud Viveka
** Last update Sat May 24 20:02:36 2014 Barneaud Viveka
*/

#include	<unistd.h>
#include	<string.h>
#include	<strings.h>
#include	<tutils.h>
#include	"prompt.h"
#include	"keyboard.h"
#include	"my_printf.h"
#include	"line_editor.h"
#include	"autocompletion.h"

char		*keep_selected(t_system *s, char *n)
{
  char		key[4096];
  int		start;

  if ((s->save = malloc_str(sizeof(*(s->save)) * (utl_strlen(n) + 1))) == NULL)
    return ("exit\n");
  start = g_pos;
  key[0] = 0;
  while (key[0] != 23 || key[0] == '\n')
    {
      if (read(0, key, 4095) == -1)
	return (n);
      if (key[0] == 27 && key[1] == 91 && key[2] == 67 && n[g_pos] != 0)
	rewrite(g_nbuf, start, g_pos++);
      if (key[0] == 27 && key[1] == 91 && key[2] == 68 && g_pos != 0)
	rewrite(g_nbuf, start, g_pos--);
    }
  if (g_pos - start >= 4095)
    return (n);
  memcpy(s->save, g_nbuf + ((start <= g_pos) ? start : g_pos),
	 (start <= g_pos) ? (g_pos - start) : (start - g_pos));
  s->save[(start <= g_pos) ? (g_pos - start) : (start - g_pos)] = '\0';
  return (n);
}

char		*my_paste(t_system *av, char *nbuf)
{
  t_buf_parts	bufp;

  if (av->save == NULL || av->save[0] == 0)
    return (nbuf);
  if (nbuf == NULL || nbuf[0] == 0)
    return (utl_strcpy(av->save));
  divide_buffer(&bufp, nbuf, av);
  free(nbuf);
  nbuf = strdup(bufp.before_cursor);
  if (nbuf == NULL)
    return ("\0");
  nbuf = realloc_and_cat(nbuf, av->save);
  nbuf = realloc_and_cat(nbuf, bufp.after_cursor);
  g_pos += utl_strlen(av->save);
  free_buf_parts(&bufp);
  return (nbuf);
}
