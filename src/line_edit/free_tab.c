/*
** free_tab.c for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/minishell
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:23:12 2014 Kevin Fouhety
** Last update Fri May 16 10:15:28 2014 Kevin Fouhety
*/

#include "line_editor.h"

void	free_dyn_sh(t_system *av, char *buf)
{
  free (buf);
}

void	free_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      free (str[i]);
      i = i + 1;
    }
  free (str[i]);
  free (str);
}
