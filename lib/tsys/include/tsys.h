/*
** tsys.h for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  2 16:51:50 2013 Laurent Fourrier
** Last update Sat May 24 17:16:01 2014 Laurent Fourrier
*/

#ifndef TSYS_H_
# define TSYS_H_

/*
** Define NULL, better than including all'o stddef
*/
# ifndef NULL
#  define NULL (void*)0
# endif

/*
** Boolean!
*/
# define FALSE 0
# define TRUE 1
typedef char t_bool;

/*
** Memory operations
*/
void	*ts_memcpy(void *src, void *dst, int size);
void	*ts_realloc(void *mem, int old_size, int new_size);
void	*ts_malloc(int size);

/*
** Error handling
*/
int	put_error(char *error);

#endif
