/*
** divide_buffer_by_wcard.c for divide_buffer_by_wcard in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Mon May 19 14:10:09 2014 Barneaud Viveka
** Last update Fri May 23 13:03:43 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	"autocompletion.h"

char		*str_before_wcard(char *cmd)
{
  char		*bw;
  int		i;

  if ((bw = malloc_str(sizeof(*bw) * (my_strlen(cmd) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (cmd[i] != 0 && cmd[i] != '*')
    {
      bw[i] = cmd[i];
      i++;
    }
  bw[i] = 0;
  return (bw);
}

char		*str_after_wcard(char *cmd)
{
  char		*aft;
  int		i;
  int		j;

  i = 0;
  if ((aft = malloc_str(sizeof(*aft) * (my_strlen(cmd) + 1))) == NULL)
    return (NULL);
  while (cmd[i] != '*' && cmd[i] != '\0')
    i++;
  if (cmd[i] != 0)
    i++;
  j = 0;
  while (cmd[i] != '\0')
    aft[j++] = cmd[i++];
  aft[j] = '\0';
  return (aft);
}

