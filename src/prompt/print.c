/*
** print.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 18:40:04 2014 Laurent Fourrier
** Last update Tue Apr 22 16:57:04 2014 Laurent Fourrier
*/

#include <tio.h>
#include "prompt.h"

void	prompt_print()
{
  if (g_prompt.prompt)
    write_str(g_fstdout, g_prompt.prompt);
  else
    write_str(g_fstdout, "FALLBACK $>");
  flush_file(g_fstdout);
}
