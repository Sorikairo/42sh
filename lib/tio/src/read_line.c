/*
** read_line.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 15:15:42 2013 Laurent Fourrier
** Last update Thu Mar 20 14:35:48 2014 Laurent Fourrier
*/

#include "tio.h"

/*
** May be deprecated in the future
** Only here for compatibility purposes
*/
char	*read_line(t_file *file)
{
  return (read_word(file, "\n"));
}
