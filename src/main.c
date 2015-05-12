/*
** main.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 19 14:27:15 2014 Laurent Fourrier
** Last update Sat May 24 14:03:58 2014 Kevin Fouhety
*/

#include <signal.h>
#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "prompt.h"
#include "system.h"
#include "script.h"
#include "arguments.h"
#include "line_editor.h"
#include "builtin.h"

static int	put_stream_error()
{
  write(1, "Unable to malloc for I/O streams\n", 34);
  return (0);
}

int		main(int argc, char **argv, char **envp)
{
  t_shell	shell;
  t_system	system;

  open_fstd();
  if (!g_fstdout)
    return (put_stream_error());
  prompt_init();
  shell = init_shell();
  system = init_system(envp);
  parse_shell_args(argc, argv, &system, &shell);
  if (shell.mode & INTERACT_MASK)
    {
      system.term = init_struct_term();
      system.pos_in_history = 0;
      exec_rtconf(&system);
      fill_history(&system);
      prompt_loop(system.term, &system);
    }
  close_fstd();
  destroy_system(&system);
  free(g_prompt.format);
  free(g_prompt.prompt);
  return (system.last_rtn);
}
