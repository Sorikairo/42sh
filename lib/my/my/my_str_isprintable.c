/*
** my_str_isprintable.c for Exo 14 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_14
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:36:17 2013 Kevin Fouhety
** Last update Tue Oct 22 08:06:00 2013 Kevin Fouhety
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] > '\0')
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
