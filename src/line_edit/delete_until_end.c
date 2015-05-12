/*
** delete_until_end.c for delete_until_end in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 14:39:03 2014 Barneaud Viveka
** Last update Sun May 25 05:24:35 2014 Kevin Fouhety
*/

#include	<string.h>
#include	<tutils.h>
#include	"system.h"
#include	"line_editor.h"
#include	"autocompletion.h"
#include	"prompt.h"

char		*delete_until_end(t_system *av, char *nbuf)
{
  int		i;
  int		j;
  int		n;

  n = 0;
  i = g_pos;
  j = utl_strlen(nbuf);
  restor_cursor_pos();
  while (n <= utl_strlen(g_prompt.prompt) + utl_strlen(nbuf))
    {
      my_putchar(' ');
      n++;
    }
  while (i != j)
    nbuf[i++] = '\0';
  return (nbuf);
}

char		*delete_before_curs(t_system *av, char *nbuf)
{
  char	*ret;
  int	i;
  int	n;

  n = 0;
  i = 0;
  if ((ret = malloc_str((utl_strlen(nbuf) + 1) * sizeof (*ret))) == NULL)
    return ("exit\n");
  while (nbuf[i + g_pos] != '\0')
    {
      ret[i] = nbuf[i + g_pos];
      i++;
    }
  ret[i] = '\0';
  restor_cursor_pos();
  while (n < (utl_strlen(g_prompt.prompt) + utl_strlen(nbuf)))
    my_printf(" ", n++);
  g_pos = utl_strlen(ret);
  free(nbuf);
  return (ret);
}

char		*my_clean(t_system *av, char *nbuf)
{
  char		*str;

  if ((str = tgetstr("clear", NULL)) == NULL)
    {
      my_printf("tgetstr failed\n");
      return ("exit\n");
    }
  my_printf("%s", str);
  if ((str = tgoto(str, 0, 0)) == NULL)
    return ("exit\n");
  my_printf("%s", str);
  save_the_line();
  return (nbuf);
}
