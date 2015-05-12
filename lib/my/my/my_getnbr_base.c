/*
** my_getnbr_base.c for Exo 16 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_16
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Oct 10 15:41:46 2013 Kevin Fouhety
** Last update Fri Dec 27 11:54:15 2013 Kevin Fouhety
*/

#include "my.h"

int	sign(int ct, int n)
{
  if (n % 2 == 1)
    return (-ct);
  if (n % 2 == 0)
    return (ct);
  return (ct);
}

int	neg(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] == '-')
    i = i + 1;
  return (i);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	f;
  int	l;
  int	ct;
  int	n;

  n = neg(str);
  ct = 0;
  i = my_strlen(str) - 1;
  f = 0;
  while (i >= 0 && str[i] != '-')
    {
      l = 0;
      while (base[l] != str[i])
	l = l + 1;
      if (str[i] == base[l])
	ct = ct + (l * (my_power_rec(my_strlen(base), f)));
      f = f + 1;
      i = i - 1;
    }
  ct = sign(ct, n);
  return (ct);
}
