/*
** my_str_isalpha.c for Exo 10 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_10
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 18:59:22 2013 Kevin Fouhety
** Last update Tue Oct 22 08:04:27 2013 Kevin Fouhety
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] > '\0')
    {
      if (str[i] <= 'z' && str[i] >= 'a')
	i = i + 1;
      else if (str[i] <= 'Z' && str[i] >= 'A')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
