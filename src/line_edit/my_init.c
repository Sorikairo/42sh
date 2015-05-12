/*
** my_init.c for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/minishell
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Feb 26 16:29:12 2014 Kevin Fouhety
** Last update Sat May 24 10:23:42 2014 Kevin Fouhety
*/

#include "line_editor.h"

t_term		*init_struct_term()
{
  t_term        *term;

  if ((term = malloc (2 * sizeof (struct termios))) == NULL)
    return (NULL);
  if ((term->t = malloc (sizeof (struct termios))) == NULL)
    return (NULL);
  if ((term->t_back = malloc (sizeof (struct termios))) == NULL)
    return (NULL);
  term = my_set_termio(term);
  return (term);
}
