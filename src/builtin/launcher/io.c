/*
** io.c for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar  8 09:08:07 2014 Laurent Fourrier
** Last update Sat Mar  8 10:30:37 2014 Laurent Fourrier
*/

#include <unistd.h>

void	redir_io(int fd_in, int fd_out)
{
  char	buf[1024];
  int	bytes_read;

  while ((bytes_read = read(fd_in, buf, 1024)) > 0)
    {
      if (write(fd_out, buf, bytes_read) < 1)
	break;
    }
}
