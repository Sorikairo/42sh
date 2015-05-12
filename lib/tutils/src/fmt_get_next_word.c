/*
** fmt_get_next_word.c for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb  4 11:26:04 2014 Laurent Fourrier
** Last update Sun Mar  9 13:19:28 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>

int	fmt_get_escaped(char c, int escaped)
{
  if (escaped == 3)
    return (2);
  if (escaped == 2)
    return (fmt_get_escaped(c, 0));
  if (c == '\\' && !escaped)
    return (3);
  if (c == '"')
    return (!escaped);
  return (escaped);
}

int	fmt_strend(char c, char *seps, int escaped)
{
  if (!escaped)
    {
      while (*seps != '\0')
	{
	  if (c == *seps++)
	    return (1);
	}
    }
  return (c == '\0');
}

int	fmt_get_next_word_len(char *str, char *seps, char **next)
{
  int	rtn;
  int	escaped;

  while (*str && fmt_strend(*str, seps, 0))
    str++;
  rtn = 0;
  escaped = fmt_get_escaped(*str, 0);
  while (!fmt_strend(*str, seps, escaped))
    {
      if (!(*str == '\\' && escaped == 3) && !(*str == '"' && escaped != 2))
	rtn++;
      str++;
      escaped = fmt_get_escaped(*str, escaped);
    }
  if (next != NULL)
    *next = str;
  return (rtn);
}

char	*fmt_get_next_word(char *str, char *seps, char **next)
{
  char	*rtn;
  int	it;
  int	escaped;

  while (*str && fmt_strend(*str, seps, 0))
    str++;
  if ((rtn = ts_malloc(fmt_get_next_word_len(str, seps, NULL) + 1)) == NULL)
    return (NULL);
  it = 0;
  escaped = fmt_get_escaped(*str, 0);
  while (!fmt_strend(*str, seps, escaped))
    {
      if (!(*str == '\\' && escaped == 3) && !(*str == '"' && escaped != 2))
	rtn[it++] = *str;
      str++;
      escaped = fmt_get_escaped(*str, escaped);
    }
  rtn[it] = '\0';
  if (next != NULL)
    *next = str;
  return (rtn);
}
