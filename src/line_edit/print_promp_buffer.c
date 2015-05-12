/*
** print_pomp_buffer.c for 42sh in /home/fouhet_k/rendu/PSU_2013_minishell2/42sh/source
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Apr  7 10:26:37 2014 Kevin Fouhety
** Last update Sat May 24 15:05:03 2014 Kevin Fouhety
*/

#include <tutils.h>
#include <sys/ioctl.h>
#include "line_editor.h"
#include "prompt.h"

int     number_carac(int nb)
{
  int   i;

  i = 1;
  while (nb >= 10)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}

char	*print_revers(char c)
{
  char	*str;

  if ((str = tgetstr("mr", NULL)) == NULL)
    {
      my_putstr("\nError tgetstr \"mr\"\n");
      g_nbuf = "exit\n";
      return (NULL);
    }
  my_putstr(str);
  my_putchar(c);
  if ((str = tgetstr("me", NULL)) == NULL)
    {
      my_putstr("\nError tgetstr \"me\"\n");
      g_nbuf = "exit\n";
      return (NULL);
    }
  my_putstr(str);
  return ("ok");
}

void  	restor_cursor_pos()
{
  char	*start;

  if ((start = tgetstr("rc", NULL)) == NULL)
    {
      my_putstr("\nError tgetstr \"rc\"\n");
      free(g_nbuf);
      g_nbuf = utl_strcpy("exit\n");
    }
  my_putstr(start);
}

void    print_promp_buffer(char *nbuf)
{
  int   i;

  i = 0;
  restor_cursor_pos();
  prompt_print();
  if (utl_strcmp("exit\n", nbuf) == 0)
    return ;
  while (nbuf[i] != '\0')
    {
      if ((i == g_pos) && (print_revers(nbuf[i]) == NULL))
	return ;
      if (i != g_pos)
	my_putchar(nbuf[i]);
      i++;
    }
  if ((g_pos == utl_strlen(nbuf)) && ((print_revers(' ')) == NULL))
    return ;
  else
    my_putchar(' ');
}

void    print_promp_buffer_del(char *nbuf, char *buf)
{
  int   i;

  i = 0;
  restor_cursor_pos();
  prompt_print();
  if (utl_strcmp("exit\n", nbuf) == 0)
    return ;
  while (nbuf[i] != '\0')
    {
      if ((i == g_pos) && (print_revers(nbuf[i]) == NULL))
	  return ;
      if (i != g_pos)
	my_putchar(nbuf[i]);
      i++;
    }
  if ((g_pos == utl_strlen(nbuf)) && (print_revers(' ') == NULL))
    return ;
  else
    my_putchar(' ');
  my_printf("  \b");
  free (buf);
}
