/*
** is_writable.c for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Feb  5 15:14:30 2014 Laurent Fourrier
** Last update Sun Apr 13 15:43:20 2014 Laurent Fourrier
*/

#include "tio.h"

int	is_writable(t_file *file)
{
  return (file && file->mode & FILE_W);
}
