/*
** strlen.c for tutils in /home/fourri_l/Projects/PSU_2013_minishell1/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Dec 17 17:24:38 2013 Laurent Fourrier
** Last update Tue Dec 17 17:26:19 2013 Laurent Fourrier
*/

int	utl_strlen(char *str)
{
  int	it;

  it = 0;
  while (str[it] != '\0')
    it++;
  return (it);
}
