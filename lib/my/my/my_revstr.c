/*
** my_strcpy.c for Exo 01 in /home/fouhet_k/rendu/Piscine-C-Jour_06
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 08:48:34 2013 Kevin Fouhety
** Last update Fri Dec 27 11:45:38 2013 Kevin Fouhety
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int st;
  int ed;
  char i;
  
  ed = my_strlen(str) - 1;
  st = 0;
  while (ed > st)
    {
      i = str[st];
      str[st] = str[ed];
      str[ed] = i;
      ed = ed -1;
      st = st + 1;
    }
  return (str);
}
