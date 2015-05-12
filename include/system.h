/*
** system.h for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 11:40:37 2014 Laurent Fourrier
** Last update Sat May 24 16:34:51 2014 Barneaud Viveka
*/

#ifndef			SYSTEM_H_
# define		SYSTEM_H_

# include		<unistd.h>
# include		"struct.h"

# define		VARIABLE_CHAR	'$'
# define		VARIABLE_SEPS	"$ \t\"'\n{}"

# define		LOGIN_MASK	0x01
# define		INTERACT_MASK	0x02

typedef struct		s_shell
{
  int			mode;
}			t_shell;

typedef struct		s_system
{
  int			last_elem;
  int			pos_in_history;
  char			**env;
  int			quit;
  int			wait;
  int			promp;
  int			last_rtn;
  char			*save;
  t_term	        *term;
  pid_t			child_pid;
  struct s_history	*history;
  struct s_alias	*alias;
}			t_system;

typedef struct		s_sigmsg
{
  int			sig;
  char			*msg;
}			t_sigmsg;

t_shell			init_shell();
t_system		init_system(char **env);

void			destroy_system(t_system *system);

void			wait_proc(t_system *sys, pid_t pid);

#endif			/* SYSTEM_H_ */
