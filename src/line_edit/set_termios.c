/*
** set_termios.c for 42sh in /home/fouhet_k/rendu/PSU_2013_minishell2/42sh/source
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Apr  7 10:16:23 2014 Kevin Fouhety
** Last update Mon Apr  7 16:57:21 2014 Kevin Fouhety
*/

#include "line_editor.h"

t_term	*my_set_termio(t_term *term)
{
  if ((tcgetattr(0, term->t)) == -1)
    return (NULL);
  if ((tcgetattr(0, term->t_back)) == -1)
    return (NULL);
  term->t->c_iflag &= BRKINT;
  term->t->c_lflag &= ~ICANON;
  term->t->c_lflag &= ~ECHO;
  term->t->c_cc[VMIN] = 1;
  term->t->c_cc[VTIME] = 0;
  return (term);
}

void	put_read_term(t_term *term)
{
  if ((tcsetattr(0, TCSANOW, term->t)) == -1)
    return ;
}

void    put_old_term(t_term *term)
{
  if ((tcsetattr(0, TCSANOW, term->t_back)) == -1)
    {
      my_printf("error tcsetattr\n");
      return ;
    }
}
