/*
** heredoc.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr 14 14:27:33 2014 Laurent Fourrier
** Last update Wed May 28 14:34:00 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tsys.h>
#include <tutils.h>
#include "system.h"
#include "builtin.h"
#include "cmdparser.h"

void		print_heredoc(char *eof, t_file *out)
{
  char		*buf;
  char		*line;
  int		buf_size;
  int		line_size;

  write_str(g_fstdout, "> ");
  flush_file(g_fstdout);
  buf = NULL;
  buf_size = 0;
  while ((line = read_line(g_fstdin)) && utl_strcmp(line, eof) != 0)
    {
      line_size = utl_strlen(line);
      buf = ts_realloc(buf, buf_size, buf_size + line_size + 2);
      buf[buf_size] = '\0';
      buf_size += line_size + 2;
      utl_strcat(utl_strcat(buf, line), "\n");
      write_str(g_fstdout, "> ");
      flush_file(g_fstdout);
      free(line);
    }
  if (buf)
    write_str(g_fstdout, buf);
  flush_file(g_fstdout);
  free(line);
  free(buf);
}

int		builtin_heredoc(t_cmd *cmd, t_system *sys)
{
  int		argc;
  t_file	*out;

  if (!cmd->args || (argc = get_wordarr_len(cmd->args)) < 2)
    {
      write_str(g_fstdout, "Error: expected string after <<\n");
      flush_file(g_fstdout);
      return (SIGRTN_NOERR);
    }
  out = fd_open_file(utl_atoi(cmd->args[0]), FILE_W);
  print_heredoc(cmd->args[1], out);
  free(out);
  return (SIGRTN_NOERR);
}
