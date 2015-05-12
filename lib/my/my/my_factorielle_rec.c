/*
** my_factorielle_rec.c for Exo 02 in /home/fouhet_k/rendu/Piscine-C-Jour_05
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Fri Oct  4 12:05:23 2013 Kevin Fouhety
** Last update Tue Oct 22 07:45:51 2013 Kevin Fouhety
*/

int	my_factorielle_rec(int nb)
{
  if (nb == 0)
    return (1);
  else if (nb > 12)
    return (0);
  else
    return ((nb) * my_factorielle_rec(nb - 1));
}
