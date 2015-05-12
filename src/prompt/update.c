/*
** update.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr 21 16:15:15 2014 Laurent Fourrier
** Last update Wed Apr 23 10:02:32 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tutils.h>
#include "system.h"
#include "prompt.h"
#include "environment.h"

int	get_total_varlen(char *str)
{
  int	it;

  it = 0;
  while (str[it] && is_wordarr_separator(str[it], VARIABLE_SEPS))
    it++;
  while (str[it] && !is_wordarr_separator(str[it], VARIABLE_SEPS))
    it++;
  if (str[it] == '}')
    it++;
  return (it);
}

int	prompt_get_size(t_system *system)
{
  char	*buf;
  int	it;
  int	rtn;

  it = 0;
  rtn = 0;
  while (g_prompt.format[it])
    {
      if (g_prompt.format[it] == VARIABLE_CHAR)
	{
	  buf = env_parsevar(system->env, g_prompt.format + it);
	  it += get_next_word_len(g_prompt.format + it, VARIABLE_SEPS);
	  rtn += utl_strlen(buf);
	}
      else
	{
	  it++;
	  rtn++;
	}
    }
  return (rtn);
}

void	prompt_update(t_system *system)
{
  char	*buf;
  int	it;

  it = 0;
  free(g_prompt.prompt);
  buf = utl_itoa(g_prompt.line_count);
  system->env = env_set(system->env, "LINE_COUNT", buf);
  free(buf);
  if ((g_prompt.prompt = ts_malloc(prompt_get_size(system) + 1)))
    {
      it = 0;
      g_prompt.prompt[0] = '\0';
      while (g_prompt.format[it])
	{
	  if (g_prompt.format[it] == VARIABLE_CHAR)
	    {
	      utl_strcat(g_prompt.prompt,
			 env_parsevar(system->env, g_prompt.format + it));
	      it += get_total_varlen(g_prompt.format + it);
	    }
	  else
	    utl_strcatc(g_prompt.prompt, g_prompt.format[it++]);
	}
    }
}
