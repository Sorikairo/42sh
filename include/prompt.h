/*
** prompt.h for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 18:36:22 2014 Laurent Fourrier
** Last update Sat May 24 16:32:25 2014 Barneaud Viveka
*/

#ifndef		PROMPT_H_
# define	PROMPT_H_

# include	"system.h"
# include	"cmdparser.h"
# include	"struct.h"

typedef struct	s_prompt
{
  char		*format;
  char		*prompt;
  int		line_count;
}		t_prompt;

/*
** Unfortunately we need that global to be able to print the prompt when
** catching a signal :(
*/

extern t_prompt	g_prompt;

/*
** Prompt display
*/
void		prompt_init();
void		prompt_print();
void		prompt_update(t_system *system);

/*
** Prompt logic
*/
void		prompt_loop(t_term *term, t_system *system);
void		prompt_print();
t_cmd		*prompt_getcmd(t_term *term, t_system *av);

#endif		/* PROMPT_H_ */
