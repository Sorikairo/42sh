/*
** remove_dta.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu May  1 19:16:18 2014 Laurent Fourrier
** Last update Thu May  1 19:41:56 2014 Laurent Fourrier
*/

#include "tlist.h"

static int	tl_ptrcmp(void *first, void *second)
{
  return (first != second);
}

t_list		*tl_remove_dta(t_list *list, void *data)
{
  return (tl_remove_dtacmp(list, data, &tl_ptrcmp));
}
