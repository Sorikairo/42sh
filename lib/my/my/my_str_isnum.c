/*
** my_str_isnum.c for Exo 11 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_11
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:34:42 2013 Kevin Fouhety
** Last update Tue Oct 22 08:05:25 2013 Kevin Fouhety
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] > '\0')
    {
      if (str[i] <= '9' && str[i] >= '0')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
