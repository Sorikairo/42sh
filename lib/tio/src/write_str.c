/*
** write_str.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Feb  6 13:02:22 2014 Laurent Fourrier
** Last update Thu Feb  6 13:20:36 2014 Laurent Fourrier
*/

#include "tio.h"

void	write_str(t_file *file, char *str)
{
  while (*str)
    write_char(file, *str++);
}
