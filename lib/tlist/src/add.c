/*
** add.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May  1 15:42:52 2014 Laurent Fourrier
** Last update Sun May  4 14:21:45 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "tlist.h"

static t_list	*tl_init_list(void *data)
{
  t_list	*rtn;

  if ((rtn = ts_malloc(sizeof(t_list))) == NULL)
    return (NULL);
  rtn->prev = NULL;
  rtn->data = data;
  rtn->next = NULL;
  return (rtn);
}

t_list		*tl_add(t_list *list, void *data)
{
  t_list	*cur;

  if (!list)
    return (tl_init_list(data));
  cur = list;
  while (cur->next)
    cur = cur->next;
  cur->next = tl_init_list(data);
  cur->next->prev = cur;
  return (list);
}
