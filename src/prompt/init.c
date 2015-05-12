/*
** init.c for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr 21 16:07:27 2014 Laurent Fourrier
** Last update Tue Apr 22 17:26:23 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tutils.h>
#include "prompt.h"

t_prompt	g_prompt;

void		prompt_init(t_system *system)
{
  g_prompt.format = utl_strcpy("(${USER}@${HOSTNAME} ${LINE_COUNT})");
  g_prompt.prompt = NULL;
  g_prompt.line_count = 1;
}
