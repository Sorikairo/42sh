/*
** my_strstr.c for Exo 04 in /home/fouhet_k/rendu/Piscine-C-Jour_06
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 11:34:36 2013 Kevin Fouhety
** Last update Tue Oct 22 08:10:33 2013 Kevin Fouhety
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	l;

  i = 0;
  l = 0;
  while (str[i])
    {
      if (str[i] == to_find[l])
	l = l + 1;
      else
	l = 0;
      if (to_find[l] == '\0')
	{
	  i = i - (l - 1);
	  return (str + i);
	}
      i = i + 1;
    }
  return ("NULL");
}
