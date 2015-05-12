/*
** wordarr_cpy.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb 19 13:47:14 2014 Laurent Fourrier
** Last update Thu Feb 20 17:00:33 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "tutils.h"

char	**wordarr_cpy(char **wordarr)
{
  char	**rtn;
  int	it;
  int	len;

  len = get_wordarr_len(wordarr);
  if ((rtn = ts_malloc((len + 1) * sizeof(void*))) == NULL)
    return (NULL);
  it = 0;
  while (it < len)
    {
      rtn[it] = utl_strcpy(wordarr[it]);
      it++;
    }
  rtn[it] = NULL;
  return (rtn);
}
