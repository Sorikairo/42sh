/*
** my_is_prime.c for Exo 08 in /home/fouhet_k/rendu/Piscine-C-Jour_05
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Oct  4 17:22:16 2013 Kevin Fouhety
** Last update Fri Dec 27 11:43:19 2013 Kevin Fouhety
*/

int	my_is_prime(int nb)
{
  int	b;

  b = 2;
  while (b <= (nb / 2))
    {
      if (nb == 0 || nb == 1)
	return (0);
      if ((nb % b) == 0)
	return (1);
      b = b + 1;
    }
  return (0);
}
