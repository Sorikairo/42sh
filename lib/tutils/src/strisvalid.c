/*
** strisvalid.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Apr  3 17:09:54 2014 Laurent Fourrier
** Last update Sat Apr  5 13:14:46 2014 Laurent Fourrier
*/

#include "tutils.h"

int	utl_charisvalid(char c, char *valids)
{
  while (*valids)
    {
      if (c == *valids++)
	return (1);
    }
  return (0);
}

int	utl_strisvalid(char *str, char *valids)
{
  while (*str)
    {
      if (!utl_charisvalid(*str++, valids))
	return (0);
    }
  return (1);
}
