/*
** xfree.c for xfree in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Sat May 24 11:06:15 2014 Barneaud Viveka
** Last update Sat May 24 11:06:37 2014 Barneaud Viveka
*/

#include	<stdlib.h>

void		xfree(void *ptr)
{
  if (ptr == NULL)
    return;
  free(ptr);
}
