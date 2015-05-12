/*
** launch.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr 23 10:30:12 2014 Laurent Fourrier
** Last update Sun May 25 17:32:36 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"

void	launch_script(t_file *file, t_system *system)
{
  char	*line;
  char	*path;
  t_cmd	*cmd;

  while ((line = read_line(file)))
    {
      path = create_path(system->env);
      cmd = cmd_parse(line, system);
      if (cmd)
	{
	  cmd_transform(cmd, system);
	  cmd_get_paths(cmd, path);
	  process_cmdlist(cmd, system);
	  destroy_cmdlist(cmd);
	}
      free(line);
      free(path);
    }
}
