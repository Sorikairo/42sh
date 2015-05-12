/*
** my_strlowcase.c for Exo 08 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_08
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:34:01 2013 Kevin Fouhety
** Last update Tue Oct 22 08:08:00 2013 Kevin Fouhety
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 90 && str[i] >= 65)
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
