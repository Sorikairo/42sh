/*
** is_cmd.c for is_cmd in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 13:37:24 2014 Barneaud Viveka
** Last update Sat May 24 11:43:26 2014 Barneaud Viveka
*/

#include	<string.h>
#include	<tutils.h>
#include	"autocompletion.h"

int		is_operator(char *cmd)
{
  if (strcmp(cmd, "|") == 0 ||
      strcmp(cmd, "||") == 0 ||
      strcmp(cmd, "&&") == 0)
    return (0);
  return (1);
}

int		is_command(char *request)
{
  char		**wtab;
  int		k;

  if (strlen(request) >= 1 && (request[utl_strlen(request) - 1] == ' ' ||
			       request[utl_strlen(request) - 1] == '\t'))
    return (1);
  wtab = my_str_to_wtab(request, " \t");
  if (count_slot(wtab) < 2)
    {
      free_wtab(wtab);
      return (0);
    }
  k = count_slot(wtab) - 2;
  if (is_operator(wtab[k]) == 0)
    {
      free_wtab(wtab);
      return (0);
    }
  free_wtab(wtab);
  return (1);
}
