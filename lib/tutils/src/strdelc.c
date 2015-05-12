/*
** strdelc.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Mar 28 13:17:30 2014 Laurent Fourrier
** Last update Sat Mar 29 03:04:12 2014 Laurent Fourrier
*/

void	utl_strdelc_shift(char *str)
{
  while (*str)
    {
      str[0] = str[1];
      str++;
    }
}

char	utl_strdelc_check(char c, char *dels)
{
  while (*dels)
    {
      if (c == *dels++)
	return (1);
    }
  return (0);
}

char	*utl_strdelc(char *str, char *dels)
{
  int	it;

  it = 0;
  while (str[it])
    {
      if (utl_strdelc_check(str[it], dels))
	utl_strdelc_shift(str + it);
      else
	it++;
    }
  return (str);
}
