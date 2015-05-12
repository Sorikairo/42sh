/*
** itoa.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 11 12:59:46 2014 Laurent Fourrier
** Last update Tue Feb 11 16:55:00 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>

int	utl_itoa_len(int nbr)
{
  int	rtn;

  rtn = 0;
  if (nbr <= 0)
    rtn++;
  while (nbr != 0)
    {
      nbr /= 10;
      rtn++;
    }
  return (rtn);
}

char	*utl_itoa(int nbr)
{
  char	*rtn;
  int	it;
  int	neg;

  it = utl_itoa_len(nbr) - 1;
  neg = (nbr < 0) ? 1 : 0;
  nbr *= neg ? -1 : 1;
  if ((rtn = ts_malloc(it + 2)) == NULL)
    return (NULL);
  rtn[it + 1] = '\0';
  while (it >= neg)
    {
      rtn[it] = (nbr % 10) + '0';
      nbr /= 10;
      it--;
    }
  if (neg)
    rtn[it] = '-';
  return (rtn);
}
