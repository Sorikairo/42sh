/*
** my_strcmp.c for Exo 05 in /home/fouhet_k/rendu/Piscine-C-Jour_06
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 14:54:26 2013 Kevin Fouhety
** Last update Tue Dec 10 18:40:38 2013 Kevin Fouhety
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
      j = j + s1[i] - s2[i];
      i = i + 1;
    }
  if (s1[i] != s2[i])
    {
      j = s1[i] - s2[i];
    }
  return (j);
}
