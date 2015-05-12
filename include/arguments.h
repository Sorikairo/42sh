/*
** arguments.h for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 25 20:58:56 2014 Laurent Fourrier
** Last update Sat May 24 17:21:08 2014 Barneaud Viveka
*/

#ifndef		ARGUMENTS_H_
# define	ARGUMENTS_H_

# include	"system.h"

typedef int	(*t_argfunc)(int ac, char **av, t_system *sys, t_shell *sh);

typedef struct	s_arghandler
{
  char		id_c;
  char		*id_s;
  t_argfunc	func;
}		t_arghandler;

void		parse_shell_args(int ac, char **av, t_system *sys, t_shell *sh);

int		arg_command(int ac, char **av, t_system *sys, t_shell *sh);
int		arg_interactive(int ac, char **av, t_system *sys, t_shell *sh);
int		arg_login_shell(int ac, char **av, t_system *sys, t_shell *sh);
int		arg_restricted(int ac, char **av, t_system *sys, t_shell *sh);
int		arg_stdin(int ac, char **av, t_system *sys, t_shell *sh);

#endif		/* ARGUMENTS_H_ */
