/*
** my_strncmp.c for Exo 06 in /home/fouhet_k/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Mon Oct  7 22:33:03 2013 Kevin Fouhety
** Last update Fri Dec 27 11:46:15 2013 Kevin Fouhety
*/

int	my_strncmp(char *s1, char *s2,int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
    i = i + 1;
  if (i == n)
    return (0);
  if (s1[i] != s2[i])
    j = s1[i] - s2[i];
  return (j);
}
