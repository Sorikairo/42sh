/*
** my_strupcase.c for Exo 07 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 17:40:41 2013 Kevin Fouhety
** Last update Tue Oct 22 08:11:19 2013 Kevin Fouhety
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] <= 122 && str[i] >= 97)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
