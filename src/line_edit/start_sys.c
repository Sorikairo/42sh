/*
** start_sys.c for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/minishell
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:26:15 2014 Kevin Fouhety
** Last update Sat May 24 10:57:56 2014 Kevin Fouhety
*/

#include "line_editor.h"

char    *take_one_av(char *av)
{
  int   i;
  char  *ret;

  i = 0;
  if ((ret = malloc((my_strlen(av) + 1) * sizeof (char))) == NULL)
    return (NULL);
  while (av[i] != '\0')
    {
      ret[i] = av[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

int     my_comp_bis(char *buffer, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != buffer[i])
        return (1);
      i = i + 1;
    }
  if (buffer[i] == '=' && str[i] == '\0')
    return (0);
  return (0);
}

char    *take_env_used(char **env)
{
  char  *term;
  int   i;

  i = 0;
  if (env == NULL)
    return (NULL);
  while (env[i] != NULL && my_comp_bis(env[i], "TERM") != 0)
    i++;
  if (env[i] == NULL)
    return (NULL);
  term = take_one_av(env[i]);
  return (term);
}

char    *take_term(char **env)
{
  char  *ret;
  char  *env_used;
  int   i;
  int   n;

  i = 0;
  n = 0;
  if ((env_used = take_env_used(env)) == NULL)
    return (NULL);
  if ((ret = xmalloc (my_strlen(env_used))) == NULL)
    return (NULL);
  while (env_used[i] != '=' && env_used[i] != '\0')
    i++;
  if (env_used[i] == '=')
    i++;
  while (env_used[i + n] != '\0')
    {
      ret[n] = env_used[i + n];
      n++;
    }
  ret[n] = '\0';
  free(env_used);
  return (ret);
}
