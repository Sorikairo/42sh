/*
** my_str_isupper.c for Exo 13 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_13
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:35:53 2013 Kevin Fouhety
** Last update Tue Oct 22 08:06:30 2013 Kevin Fouhety
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] > '\0')
    {
      if (str[i] <= '~' && str[i] >= '!')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
