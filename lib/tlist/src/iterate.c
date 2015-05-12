/*
** iterate.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May  1 19:22:48 2014 Laurent Fourrier
** Last update Thu May  1 19:25:24 2014 Laurent Fourrier
*/

#include "tlist.h"

void		tl_iterate(t_list *list, tl_func_it it)
{
  while (list)
    {
      it(list->data);
      list = list->next;
    }
}
