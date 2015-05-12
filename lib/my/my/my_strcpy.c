/*
** my_strcpy.c for Exo 01 in /home/fouhet_k/rendu/Piscine-C-Jour_06
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 08:48:34 2013 Kevin Fouhety
** Last update Fri Dec 27 11:44:37 2013 Kevin Fouhety
*/

char	*my_strcpy(char *dest,char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (src[i] == '\0')
    dest[i] = src[i];
  return (dest);
}
