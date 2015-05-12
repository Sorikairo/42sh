/*
** atoi.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb  6 13:47:42 2014 Laurent Fourrier
** Last update Fri Feb  7 14:13:43 2014 Laurent Fourrier
*/

#include "tutils.h"

int	utl_isdigit(char c)
{
  return (c >= '0' && c <= '9');
}

int	utl_atoi(char *str)
{
  int	it;
  int	rtn;
  int	mult;

  rtn = 0;
  mult = 1;
  it = utl_strlen(str) - 1;
  while (it >= 0)
    {
      if (utl_isdigit(str[it]))
	{
	  rtn += (str[it] - '0') * mult;
	  mult *= 10;
	}
      else if (str[it] == '-')
	rtn *= -1;
      it--;
    }
  return (rtn);
}
