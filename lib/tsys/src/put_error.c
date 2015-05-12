/*
** put_error.c for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Dec 28 13:48:39 2013 Laurent Fourrier
** Last update Mon Dec 30 13:57:33 2013 Laurent Fourrier
*/

#include <unistd.h>

void	stderr_putchar(char c)
{
  write(2, &c, 1);
}

void	stderr_putstr(char *str)
{
  while (*str != '\0')
    stderr_putchar(*str++);
}

int	put_error(char *error)
{
  stderr_putstr("Error: ");
  stderr_putstr(error);
  stderr_putchar('\n');
  return (0);
}
