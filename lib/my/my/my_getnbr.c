/*
** getnbr.c for getnbr in /home/fouhet_k/rendu/Piscine-C-colles-Semaine_02
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sat Oct 12 14:14:37 2013 Kevin Fouhety
** Last update Fri Dec 27 12:06:34 2013 Kevin Fouhety
*/

#include "my.h"

int	neg(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] == '-')
    {
      i = i + 1;
    }
  i = i % 2;
  if (i == 0)
    return (1);
  if (i == 1)
    return (-1);
  return (0);
}

int	count(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = -1;
  while (str[i] == '-')
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      i = i + 1;
      n = n + 1;
    }
  if (i == 0 || n == 0)
    return (0);
  return (n);
}

int	my_inter_getnbr(char *str, int f)
{
  int	i;
  int	ct;
  int	n;

  ct = 0;
  n = 0;
  i = 0;
  while (str[i] == '-')
    i = i + 1;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
      n = str[i] - 48;
      ct = ct + n * f;
      i = i + 1;
      f = f / 10;
    }
  return (ct);
}

int	my_getnbr(char *str)
{
  int	ct;
  int	f;
  int	d;

  d = count(str);
  f = 1;
  while (d > 0)
    {
      f = f * 10;
      d = d - 1;
    } 
  ct = my_inter_getnbr(str, f);
  ct = ct * neg(str);
  return (ct);
}
