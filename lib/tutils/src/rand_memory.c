/*
** rand_memory.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 11 14:25:52 2014 Laurent Fourrier
** Last update Wed Mar 12 21:53:45 2014 Laurent Fourrier
*/

#include <stdlib.h>

/*
** Memory random: this randomizer works with the address of a newly
** initialized byte. Hacky stuff!
** If malloc is impossible, this function will always return 0 :(
** Please note that the larger the range is, the lesser the random factor
** applies on the return value, so please use in conjunction with another
** random method (read as: this function may only be used for generating a
** base seed!)
*/

int	utl_rand_memory(int range)
{
  void	*ptr;
  int	rtn;

  ptr = malloc(1);
  rtn = (int)(long)ptr % range;
  free(ptr);
  return (rtn);
}
