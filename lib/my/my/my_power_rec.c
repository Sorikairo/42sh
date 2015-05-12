/*
** my_power_rec.c for Exo 04 in /home/fouhet_k/rendu/Piscine-C-Jour_05
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Oct  4 14:13:23 2013 Kevin Fouhety
** Last update Tue Oct 22 07:57:19 2013 Kevin Fouhety
*/

int	my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power == 1)
    return (nb);
  return (nb * my_power_rec(nb, power - 1));
}
