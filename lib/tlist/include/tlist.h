/*
** tlist.h for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jan 22 09:26:59 2014 Laurent Fourrier
** Last update Thu May  1 19:41:15 2014 Laurent Fourrier
*/

#ifndef TLIST_H_
# define TLIST_H_

typedef struct	s_list
{
  struct s_list	*prev;
  void		*data;
  struct s_list	*next;
}		t_list;

/*
** Typedefs for functions pointers used in this lib
*/
typedef void	(*tl_func_it)(void *data);
typedef int	(*tl_func_cmp)(void *first, void *second);

/*
** List manipulation
*/
t_list		*tl_add(t_list *list, void *data);
t_list		*tl_remove(t_list *list, t_list *rm);
t_list		*tl_remove_dta(t_list *list, void *data);
t_list		*tl_remove_dtacmp(t_list *list, void *data,
				  tl_func_cmp cmp);

/*
** Data manipulation
*/
void		tl_iterate(t_list *list, tl_func_it it);

#endif
