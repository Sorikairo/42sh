/*
** remove.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May  1 15:55:54 2014 Laurent Fourrier
** Last update Sun May  4 11:39:50 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tlist.h"

t_list		*tl_remove(t_list *list, t_list *rm)
{
  t_list	*cur;

  cur = list;
  while (cur)
    {
      if (cur == rm)
	{
	  if (cur == list)
	    list = cur->next;
	  if (cur->prev)
	    cur->prev->next = cur->next;
	  if (cur->next)
	    cur->next->prev = cur->prev;
	  free(cur);
	  return (list);
	}
      cur = cur->next;
    }
  return (list);
}
