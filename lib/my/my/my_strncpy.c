/*
** my_strncpy.c for Exo 02 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_02
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 10:09:07 2013 Kevin Fouhety
** Last update Fri Dec 27 11:45:07 2013 Kevin Fouhety
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (n == i || src[i] == '\0')
    dest[i] = '\0';
  return (dest);
}
