/*
** strisnbr.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 17:49:20 2014 Laurent Fourrier
** Last update Tue Feb 25 18:18:35 2014 Laurent Fourrier
*/

int	utl_strisnbr(char *str)
{
  int	it;
  int	neg;

  it = 0;
  neg = 0;
  while (str[it] != '\0')
    {
      if (str[it] < '0' || str[it] > '9')
	{
	  if (str[it] == '-' && it == 0)
	    neg = 1;
	  else
	    return (0);
	}
      it++;
    }
  return ((neg) ? 2 : 1);
}
