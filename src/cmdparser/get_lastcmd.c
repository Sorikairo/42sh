/*
** get_lastcmd.c for 42sh in /home/fourri_l/Projects/repo-42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed May 28 13:49:54 2014 Laurent Fourrier
** Last update Wed May 28 13:50:27 2014 Laurent Fourrier
*/

#include "cmdparser.h"

t_cmd	*get_lastcmd(t_cmd *cmd)
{
  while (cmd->next)
    cmd = cmd->next;
  return (cmd);
}
