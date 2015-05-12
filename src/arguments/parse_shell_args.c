/*
** parse_shell_args.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 21:03:44 2014 Laurent Fourrier
** Last update Wed May  7 11:20:39 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tutils.h>
#include "arguments.h"

t_arghandler	g_arghandler[] =
  {
    {'c', "command", &arg_command},
    {'i', "interactive", &arg_interactive},
    {'l', "login", &arg_login_shell},
    {'r', "restricted", &arg_restricted},
    {'s', "stdin", &arg_stdin},
    {'\0', NULL, NULL}
  };

t_arghandler	get_arghandler_char(char c)
{
  int		it;

  it = 0;
  while (g_arghandler[it].func != NULL)
    {
      if (g_arghandler[it].id_c == c)
	return (g_arghandler[it]);
      it++;
    }
  return (g_arghandler[it]);
}

t_arghandler	get_arghandler_str(char *str)
{
  int		it;

  it = 0;
  while (g_arghandler[it].func != NULL)
    {
      if (utl_strcmp(g_arghandler[it].id_s, str) == 0)
	return (g_arghandler[it]);
      it++;
    }
  return (g_arghandler[it]);
}

void		parse_shell_args(int argc, char **argv,
				 t_system *sys, t_shell *shell)
{
  int		it;
  t_arghandler	handler;

  it = 1;
  while (it < argc)
    {
      if (argv[it][0] == '-')
	{
	  if (argv[it][1] == '-')
	    handler = get_arghandler_str(argv[it] + 2);
	  else
	    handler = get_arghandler_char(argv[it][1]);
	  if (handler.func != NULL)
	    it += handler.func(argc - it, argv + it, sys, shell);
	}
      it++;
    }
}
