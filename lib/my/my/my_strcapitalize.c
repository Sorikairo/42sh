/*
** my_strcapitalize.c for Exo 09 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_09
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:31:55 2013 Kevin Fouhety
** Last update Tue Oct 22 08:01:24 2013 Kevin Fouhety
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[0] <= 'z' && str[0] >= 'a')
	str[0] = str[0] - 32;
      if (str[i] <= 'Z' && str[i] >= 'A')
	str[i] = str[i] + 32;
      if (str[i] <= '/' && str[i] > '\0' && str[i] != ' ')
	{
	  i = i + 1;
	  if (str[i] <= 'z' && str[i] >= 'a')
	    str[i] = str[i] - 32;
	}
      if (str[i] == ' ')
	{
	  i = i + 1;
	  if (str[i] >= 'a' && str[i] <= 'z')
	    str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
