/*
** tsys.h for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  2 16:51:50 2013 Laurent Fourrier
** Last update Wed Feb 26 16:09:43 2014 Laurent Fourrier
*/

#ifndef TSYS_H_
# define TSYS_H_

# ifndef NULL
#  define NULL (void*)0
# endif

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
