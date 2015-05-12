/*
** command.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 21:32:00 2014 Laurent Fourrier
** Last update Tue May 13 14:45:21 2014 
*/

#include <stdlib.h>
#include <tio.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

static void	launch_command(char *line, t_system *system)
{
  char		*path;
  t_cmd		*cmd;

  path = create_path(system->env);
  cmd = cmd_parse(line, system);
  cmd_get_paths(cmd, path);
  process_cmdlist(cmd, system);
  destroy_cmdlist(cmd);
  free(path);
}

int		arg_command(int argc, char **argv,
			    t_system *sys, t_shell *shell)
{
  if (argc < 2)
    {
      write_str(g_fstdout, argv[0]);
      write_str(g_fstdout, " requires an argument\n");
      flush_file(g_fstdout);
      return (0);
    }
  shell->mode &= ~INTERACT_MASK;
  launch_command(argv[1], sys);
  return (1);
}
