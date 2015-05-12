/*
** memcpy.c for tsys in /home/fourri_l/Projects/lib/tsys
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  2 16:56:36 2013 Laurent Fourrier
** Last update Mon Dec  2 17:27:51 2013 Laurent Fourrier
*/

void	*ts_memcpy(void *src, void *dst, int size)
{
  char	*src_bytes;
  char	*dst_bytes;
  int	it;

  src_bytes = src;
  dst_bytes = dst;
  it = 0;
  while (it < size)
    {
      dst_bytes[it] = src_bytes[it];
      it++;
    }
  return (dst);
}
