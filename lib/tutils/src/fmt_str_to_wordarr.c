/*
** fmt_str_to_wordarr.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb  4 14:36:55 2014 Laurent Fourrier
** Last update Wed Feb 19 14:08:57 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "tutils.h"

int	fmt_calc_wordarr_len(char *str, char *seps)
{
  int	rtn;

  rtn = 0;
  while (fmt_get_next_word_len(str, seps, &str))
    rtn++;
  return (rtn);
}

char	**fmt_str_to_wordarr(char *str, char *seps)
{
  char	**rtn;
  int	it;
  int	len;

  len = fmt_calc_wordarr_len(str, seps);
  if ((rtn = ts_malloc((len + 1) * sizeof(void*))) == NULL)
    return (NULL);
  it = 0;
  while (it < len)
    {
      rtn[it] = fmt_get_next_word(str, seps, &str);
      it++;
    }
  rtn[it] = NULL;
  return (rtn);
}
