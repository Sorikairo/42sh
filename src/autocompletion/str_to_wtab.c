/*
** str_to_wordtab.c for str_to_wtab in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue Apr 22 09:49:08 2014 Barneaud Viveka
** Last update Sat May 24 11:46:15 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<string.h>
#include	<tutils.h>
#include	"my_printf.h"
#include	"autocompletion.h"

int		isprintable(char a, char *sep)
{
  int		i;

  i = 0;
  while (sep[i] != '\0')
    {
      if (a == sep[i])
	return (0);
      i++;
    }
  return (1);
}

int		count_word(char *str, char *sep)
{
  int		i;
  int		wd;

  wd = 0;
  i = 0;
  if (isprintable(str[0], sep) == 1)
    wd = 1;
  while (str[i] != '\0')
    {
      if (isprintable(str[i], sep) == 0 && isprintable(str[i + 1], sep) == 1)
	wd++;
      i++;
    }
  return (wd);
}

char		**my_str_to_wtab(char *str, char *sep)
{
  int		i;
  int		j;
  int		k;
  char		**wtab;

  i = 0;
  k = 0;
  if ((wtab = malloc(sizeof(*wtab) * (count_word(str, sep) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if ((wtab[k] = malloc(sizeof(wtab[k]) * (utl_strlen(str) + 1))) == NULL)
	return (NULL);
      j = 0;
      while (isprintable(str[i], sep) == 0 && str[i] != '\0')
	i++;
      while (isprintable(str[i], sep) == 1 && str[i] != '\0')
	wtab[k][j++] = str[i++];
      wtab[k][j] = '\0';
      if (str[i] != '\0')
	i++;
      k++;
    }
  wtab[k] = NULL;
  return (wtab);
}

void		show_wtab(char **wtab)
{
  int		k;

  k = 0;
  if (wtab == NULL)
    return;
  while (wtab[k] != NULL)
    {
      my_printf("%s\n", wtab[k]);
      k++;
    }
}

void		free_wtab(char **wtab)
{
  int		k;

  k = 0;
  if (wtab == NULL)
    return;
  while (wtab[k] != NULL)
    xfree(wtab[k++]);
  xfree(wtab);
}
