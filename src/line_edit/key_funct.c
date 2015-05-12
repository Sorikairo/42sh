/*
** key_funct.c for key_functs in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 14:54:47 2014 Barneaud Viveka
** Last update Sat May 24 17:35:17 2014 Barneaud Viveka
*/

#include	<tutils.h>
#include	"line_editor.h"
#include	"keyboard.h"

t_keyfct	g_keyf[8] = {
  {5, &goto_end},
  {11, &delete_until_end},
  {12, &my_clean},
  {20, &swap_char},
  {21, &delete_before_curs},
  {23, &keep_selected},
  {25, &my_paste},
  {0, NULL}
};

char		*get_key_functs(char *nbuf, char *buffer, t_system *av)
{
  int		k;

  k = 0;
  while (g_keyf[k].buf != 0)
    {
      if (buffer[0] == g_keyf[k].buf)
	nbuf = g_keyf[k].fptr(av, nbuf);
      k++;
    }
  return (nbuf);
}
