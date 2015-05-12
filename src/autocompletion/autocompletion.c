/*
** autocompletion.c for autocompletion in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 12:55:27 2014 Barneaud Viveka
** Last update Wed May 28 10:26:49 2014 Barneaud Viveka
*/

#include	<string.h>
#include	"line_editor.h"
#include	"autocompletion.h"

void		divide_buffer(t_buf_parts *bufp, char *nbuf, t_system *av)
{
  if (nbuf == NULL || nbuf[0] == '\0')
    return;
  bufp->before_cursor = str_before_cursor(nbuf, av);
  bufp->after_cursor = str_after_cursor(nbuf, av);
  bufp->status = is_command(bufp->before_cursor);
  bufp->current_wd = current_word(bufp->before_cursor);
  if (bufp->status == CMD && strncmp(nbuf, "./", 2) != 0)
    bufp->path = strdup("/usr/bin");
  else
    {
      if (strncmp(nbuf, "./", 2) == 0)
	bufp->status = XDIR;
      bufp->path = get_file_path(bufp->current_wd, av->env);
    }
  bufp->start = get_start(bufp->current_wd);
}

void		free_buf_parts(t_buf_parts *bufp)
{
  xfree(bufp->before_cursor);
  xfree(bufp->after_cursor);
  xfree(bufp->current_wd);
  xfree(bufp->path);
  xfree(bufp->start);
}

char		*autocompletion(char *nbuf, t_system *av)
{
  t_buf_parts	bufp;

  divide_buffer(&bufp, nbuf, av);
  if (nbuf == NULL || nbuf[0] == '\0' || bufp.before_cursor == NULL)
    {
      bufp.path = strdup("/usr/bin");
      bufp.start = strdup("\0");
      show_files(bufp);
      return (nbuf);
    }
  if (strncmp(nbuf, "./", 2) == 0)
    return (completion_xdir(nbuf, bufp, av));
  if (count_files(bufp) == 1)
    nbuf = new_buffer(bufp, av);
  else if (count_files(bufp) == 0)
    {
      my_printf("\nCannot find any file\n");
      save_the_line();
    }
  else
    show_files(bufp);
  free_buf_parts(&bufp);
  return (nbuf);
}
