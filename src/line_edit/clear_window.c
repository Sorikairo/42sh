/*
** clear_window.c for 42sh in /home/fouhet_k/42sh/repo-42sh/src/line_edit
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri May 16 10:32:54 2014 Kevin Fouhety
** Last update Sat May 24 15:11:17 2014 Kevin Fouhety
*/

#include "line_editor.h"

void    my_clear_window()
{
  char  *test;

  if ((test = tgetstr("clear", NULL)) != NULL)
    if ((test = tgoto(test, 0, 0)) != NULL)
      {
	tgoto(test, 0, 0);
	my_putstr(test);
	return ;
      }
  my_putstr("Error, the windows didn't clean\n");
}
