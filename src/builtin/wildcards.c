/*
** wildcards.c for wildcards in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Mon May 19 13:39:10 2014 Barneaud Viveka
** Last update Sat May 24 11:27:55 2014 Barneaud Viveka
*/

#include	<dirent.h>
#include	<string.h>
#include	<strings.h>
#include	<tutils.h>
#include	"cmdparser.h"
#include	"system.h"
#include	"autocompletion.h"

char		*put_filename_in_wtab(char *path, char *name)
{
  char		*filename;

  if (strcmp(path, ".") == 0)
    {
      filename = strdup(name);
      return (filename);
    }
  filename = strdup(path);
  filename = realloc_and_cat(filename, name);
  if (filename == NULL)
    return (utl_strcpy("\0"));
  return (filename);
}

char		**get_compatible_files(char *path, char *start, char *end)
{
  DIR		*dir;
  struct dirent	*dirp;
  t_buf_parts	bp;
  char		**alfile;
  int		k;

  bp.path = strdup(path);
  bp.start = get_start(start);
  k = 0;
  if ((alfile = malloc(sizeof(*alfile) * (count_files(bp) + 1))) == NULL)
    return (NULL);
  if ((dir = opendir(path)) == NULL)
    return (NULL);
  while ((dirp = readdir(dir)) != NULL)
    {
      if (strncmp(bp.start, dirp->d_name, utl_strlen(bp.start)) == 0 &&
	  my_strendcmp(end, dirp->d_name) == 0 &&
	  dirp->d_name[0] != '.')
	alfile[k++] = put_filename_in_wtab(path, dirp->d_name);
    }
  alfile[k] = NULL;
  return (alfile);
}

char		**replace_star(char **args, char **env, int k)
{
  char		*start;
  char		*end;
  char		*path;
  char		**files;

  start = str_before_wcard(args[k]);
  end = str_after_wcard(args[k]);
  path = get_file_path(start, env);
  files = get_compatible_files(path, start, end);
  xfree(path);
  xfree(start);
  xfree(end);
  if (files == NULL)
    return (args);
  args = add_files_to_args(args, files, k);
  return (args);
}

void		check_if_wildcard(t_cmd *cmd, t_system *sys)
{
  int		i;
  int		k;

  k = 0;
  while (cmd->args[k] != NULL)
    {
      i = 0;
      while (cmd->args[k][i] != 0)
	{
	  if (cmd->args[k][i] == '*')
	    {
	      cmd->args = replace_star(cmd->args, sys->env, k);
	      if (cmd->args == NULL || cmd->args[k] == NULL)
		return;
	    }
	  i++;
	}
      k++;
    }
}
