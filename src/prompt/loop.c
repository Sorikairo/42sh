/*
** loop.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 18:38:40 2014 Laurent Fourrier
** Last update Sun May 25 17:32:50 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "prompt.h"
#include "builtin.h"
#include "cmdparser.h"
#include "environment.h"
#include "line_editor.h"

void    delet_cursor()
{
  char  *str;

  if ((str = tgetstr("vi", NULL)) != NULL)
    my_putstr(str);
  else
    my_putstr("Error to clean the cursor\n");
}

void	put_tgetent(char *name_term, t_term *term)
{
  if (name_term != NULL)
    {
      tgetent(NULL, name_term);
      free(name_term);
    }
  else
    tgetent(NULL, "xterm");
  if (term != NULL)
    delet_cursor();
}

void	put_cursor()
{
  char	*str;

  if ((str = tgetstr("ve", NULL)) == NULL)
    my_putstr("Error to put the cursor back\n");
  else
    my_putstr(str);

}

void	prompt_loop(t_term *term, t_system *system)
{
  char	*path;
  t_cmd	*cmd;

  put_tgetent(take_term(system->env), term);
  if (!system->quit && term != NULL)
    my_clear_window();
  while (!system->quit)
    {
      path = create_path(system->env);
      prompt_update(system);
      cmd = prompt_getcmd(term, system);
      if (cmd != NULL)
  	{
	  cmd_transform(cmd, system);
  	  cmd_get_paths(cmd, path);
  	  if (process_cmdlist(cmd, system) == SIGRTN_EXIT)
  	    system->quit = 1;
  	  destroy_cmdlist(cmd);
  	  g_prompt.line_count++;
  	}
      free(path);
    }
  if (term != NULL)
    my_free_struct(term);
  put_cursor();
}
