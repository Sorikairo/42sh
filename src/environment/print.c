/*
** print.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Mar  3 11:29:50 2014 Laurent Fourrier
** Last update Mon Mar  3 12:39:35 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>

void	env_print(char **env)
{
  while (*env != NULL)
    {
      write_str(g_fstdout, *env++);
      write_char(g_fstdout, '\n');
    }
  flush_file(g_fstdout);
}
