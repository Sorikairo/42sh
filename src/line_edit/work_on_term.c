/*
** work_on_term.c for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/minishell
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Feb 27 08:00:39 2014 Kevin Fouhety
** Last update Sat May 24 19:10:25 2014 Kevin Fouhety
*/

#include <tutils.h>
#include "line_editor.h"
#include "autocompletion.h"

void	my_free_struct(t_term *term)
{
  free (term->t);
  free (term->t_back);
  free (term);
}

char	*find_if_null(char *ret)
{
  if (ret[0] == '\0')
    {
      free (ret);
      return (utl_strcpy(""));
    }
  return (ret);
}

char    *work_on_nbuf(char *nbuf, t_system *av, t_term *term, char *buffer)
{
  int	i;

  i = utl_strlen(buffer);
  if (i == 1)
    nbuf = buffer_one_lenth(buffer, nbuf, av);
  else if (i == 3)
    nbuf = buffer_three_lenth(buffer, nbuf, av);
  else if (i == 4 && buffer[0] == 27 && buffer[1] == 91 &&
	   buffer[2] == 51 && buffer[3] == 126)
    nbuf = delet_char(nbuf, av, g_pos);
  else if (i == 6 && buffer[0] == 27 && buffer[1] == 91 &&
	   (buffer[5] == 67 || buffer[5] == 68))
    g_pos = take_new_pos(nbuf, g_pos, buffer[5]);
  return (nbuf);
}

char	*delet_char(char *buf, t_system *av, int pos)
{
  char	*ret;
  int	i;

  i = 0;
  if (utl_strlen(buf) == pos)
    {
      my_putchar('\a');
      return (buf);
    }
  if ((ret = malloc(my_strlen(buf) + 1)) == NULL)
    return ("exit\n");
  while (buf[i] != '\0' && i != g_pos)
    {
      ret[i] = buf[i];
      i++;
    }
  while (buf[i] != '\0' && buf[i + 1] != '\0')
    {
      ret[i] = buf[i + 1];
      i++;
    }
  ret[i] = '\0';
  print_promp_buffer_del(ret, buf);
  return (find_if_null(ret));
}

char	*delet_last_char(char *buf, t_system *av, int pos)
{
  char	*ret;
  int	i;

  i = 0;
  if (pos == 0)
    {
      my_putchar('\a');
      return (buf);
    }
  if ((ret = malloc (my_strlen(buf) + 1)) == NULL)
    return (utl_strcpy("\n"));
  while (buf[i] != '\0' && (i + 1) != g_pos)
    {
      ret[i] = buf[i];
      i++;
    }
  while (buf[i] != '\0' && buf[i + 1] != '\0')
    {
      ret[i] = buf[i + 1];
      i++;
    }
  g_pos--;
  ret[i] = '\0';
  print_promp_buffer_del(ret, buf);
  return (find_if_null(ret));
}
