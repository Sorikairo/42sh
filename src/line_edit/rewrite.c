/*
** rewrite.c for rewrite in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat May 24 18:03:24 2014 Barneaud Viveka
** Last update Sat May 24 19:58:07 2014 Barneaud Viveka
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

void		rewrite(char *nbuf, int start, int end)
{
  int		i;

  i = 0;
  restor_cursor_pos();
  prompt_print();
  if (utl_strcmp("exit\n", nbuf) == 0)
    return ;
  while (nbuf[i] != '\0')
    {
      if ((i == g_pos) || (i >= start && i <= end) ||
	  (i <= start && i >= end))
	{
	  if (print_revers(nbuf[i]) == NULL)
	    return;
	}
      else if (i != g_pos)
	my_putchar(nbuf[i]);
      i++;
    }
  if ((g_pos == utl_strlen(nbuf)) && ((print_revers(' ')) == NULL))
    return ;
  else
    my_putchar(' ');
}
