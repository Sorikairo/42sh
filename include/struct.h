/*
** struct.h for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:27:47 2014 Kevin Fouhety
** Last update Sat May 24 16:33:40 2014 Barneaud Viveka
*/

#ifndef			STRUCT_H_
# define		STRUCT_H_

typedef struct		s_term
{
  struct termios	*t;
  struct termios	*t_back;
}			t_term;

#endif			/* STRUCT_H_ */
