/*
** keyboard.h for keyboard in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May 13 15:34:25 2014 Barneaud Viveka
** Last update Mon May 19 10:48:48 2014 Barneaud Viveka
*/

#ifndef		KEYBOARD_H_
# define	KEYBOARD_H_

#include	"system.h"

typedef struct	s_keyfct
{
  int		buf;
  char		*(*fptr)(t_system *av, char *nbuf);
} t_keyfct;

char		*get_key_functs(char *nbuf, char *buffer, t_system *av);
char		*delete_until_end(t_system *av, char *nbuf);
char		*my_clean(t_system *av, char *nbuf);
char		*goto_end(t_system *av, char *nbuf);
char		*swap_char(t_system *av, char *nbuf);
char		*delete_before_curs(t_system *av, char *nbuf);
char		*keep_selected(t_system *s, char *nbuf);
char		*my_paste(t_system *av, char *nbuf);

#endif		/* KEYBOARD_H_ */
