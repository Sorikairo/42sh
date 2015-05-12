/*
** atod.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 12 17:16:08 2014 Laurent Fourrier
** Last update Fri Mar 14 14:19:12 2014 Laurent Fourrier
*/

#include "tutils.h"

int		utl_atod_isdigit(char c)
{
  return (c >= '0' && c <= '9');
}

double		utl_make_mult(int digits)
{
  double	rtn;

  if (digits < 1)
    return (0.0);
  rtn = 1.0;
  while (digits-- > 1)
    rtn *= 10.0;
  return (rtn);
}

double		utl_get_mult(char *str)
{
  int		it;

  it = 0;
  while (str[it])
    {
      if (!utl_atod_isdigit(str[it]))
	return (utl_make_mult(it));
      it++;
    }
  return (utl_make_mult(it));
}

double		utl_atod(char *str)
{
  int		it;
  double	mult;
  double	rtn;

  it = (str[0] == '-') ? 1 : 0;
  mult = utl_get_mult(str + it);
  rtn = 0.0;
  while (str[it] && (str[it] == '.' || utl_atod_isdigit(str[it])))
    {
      if (str[it] != '.')
	{
	  rtn += mult * (str[it] - '0');
	  mult /= 10.0;
	}
      it++;
    }
  return ((str[0] == '-') ? -rtn : rtn);
}
