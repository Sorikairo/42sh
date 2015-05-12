/*
** str_to_wordarr.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Dec  5 18:32:14 2013 Laurent Fourrier
** Last update Mon May 19 14:20:19 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>

int	is_wordarr_separator(char c, char *seps)
{
  while (*seps)
    {
      if (*seps++ == c)
	return (1);
    }
  return (0);
}

int	calc_wordarr_len(char *str, char *seps)
{
  int	rtn;
  int	in_word;

  rtn = 0;
  in_word = 0;
  while (*str != '\0')
    {
      if (!in_word && !is_wordarr_separator(*str, seps))
	rtn++;
      if (in_word == is_wordarr_separator(*str, seps))
	in_word = !in_word;
      str++;
    }
  return (rtn);
}

int	get_next_word_len(char *str, char *seps)
{
  int	rtn;

  rtn = 0;
  while (is_wordarr_separator(*str, seps) && *str != '\0')
    str++;
  while (!is_wordarr_separator(*str, seps) && *str != '\0')
    {
      rtn++;
      str++;
    }
  return (rtn);
}

char	*get_next_word(char *str, char *seps, char **next)
{
  char	*rtn;
  int	it;

  it = 0;
  if ((rtn = ts_malloc(get_next_word_len(str, seps) + 1)) == NULL)
    return (NULL);
  while (is_wordarr_separator(*str, seps) && *str != '\0')
    str++;
  while (!is_wordarr_separator(*str, seps) && *str != '\0')
    {
      rtn[it] = *str;
      str++;
      it++;
    }
  rtn[it] = '\0';
  while (is_wordarr_separator(*str, seps) && *str != '\0')
    str++;
  if (next)
    *next = str;
  return (rtn);
}

char	**str_to_wordarr(char *str, char *seps)
{
  char	**rtn;
  int	it;
  int	wordarr_len;

  wordarr_len = calc_wordarr_len(str, seps);
  if ((rtn = ts_malloc((wordarr_len + 1) * sizeof(void*))) == NULL)
    return (NULL);
  it = 0;
  while (it < wordarr_len)
    rtn[it++] = get_next_word(str, seps, &str);
  rtn[it] = NULL;
  return (rtn);
}
