/*
** get_openflags.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Jan 14 13:26:38 2014 Laurent Fourrier
** Last update Tue Mar 25 09:18:50 2014 Laurent Fourrier
*/

#include <fcntl.h>
#include "tio.h"

typedef struct	s_flags
{
  int		tio_flag;
  int		sys_flag;
}		t_flags;

t_flags	g_flags[] = 
  {
    {FILE_R, O_RDONLY},
    {FILE_W, O_WRONLY | O_CREAT | O_TRUNC},
    {-1, -1}
  };

int	get_openflags(int mode)
{
  int	it;
  int	rtn;

  it = 0;
  rtn = 0;
  while (g_flags[it].tio_flag != -1)
    {
      if (mode & g_flags[it].tio_flag)
	rtn |= g_flags[it].sys_flag;
      it++;
    }
  return (rtn);
}
