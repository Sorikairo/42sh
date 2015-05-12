/*
** my_strlen.c for Exo 03 in /home/fouhet_k/rendu/Piscine-C-Jour_04
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Oct  3 14:07:22 2013 Kevin Fouhety
** Last update Wed Oct 30 16:15:35 2013 Kevin Fouhety
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
