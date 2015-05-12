/*
** rand_vneumann.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 11 16:42:31 2014 Laurent Fourrier
** Last update Tue Mar 11 18:18:44 2014 Laurent Fourrier
*/

/*
** Van Neumann random: this randomizer works from a given seed.
** While it is more "random" than the memory random function (and less hacky),
** the range of this implementation is also less configurable: the range is
** fixed to 4 (it should be okay for most things though)
*/

int	utl_rvn_getdigits(int nbr)
{
  int	rtn;

  rtn = 0;
  while (nbr != 0)
    {
      nbr /= 10;
      rtn++;
    }
  return (rtn);
}

/*
** This function is the holy incarnation of wierdness. But it works.
*/
int	utl_rvn_getrtn(int nbr)
{
  int	it;
  int	digits;

  digits = utl_rvn_getdigits(nbr) / 2;
  it = 2;
  while (it++ < digits)
    nbr /= 10;
  nbr %= 10000;
  return (nbr);
}

/*
** Clunky implementation, but fuck this I have rtv1 to finish
*/
int	utl_rand_vneumann(int seed)
{
  seed = seed * seed;
  while (seed < 100000)
    {
      seed++;
      seed = seed * seed;
      seed = (seed < 0) ? -seed : seed;
    }
  return (utl_rvn_getrtn(seed));
}
