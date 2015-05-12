/*
** remove_dtacmp.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May  1 15:50:27 2014 Laurent Fourrier
** Last update Thu May  1 15:55:44 2014 Laurent Fourrier
*/

#include "tlist.h"

t_list		*tl_remove_dtacmp(t_list *list, void *data, tl_func_cmp cmp)
{
  t_list	*cur;

  cur = list;
  while (cur)
    {
      if (cmp(data, cur->data) == 0)
	{
	  list = tl_remove(list, cur);
	  cur = list;
	}
      else
	cur = cur->next;
    }
  return (list);
}
