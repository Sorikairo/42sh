/*
** builtin.h for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb 25 14:05:35 2014 Laurent Fourrier
** Last update Sat May 24 17:26:12 2014 Barneaud Viveka
*/

#ifndef		BUILTIN_H_
# define	BUILTIN_H_

# include	"system.h"
# include	"cmdparser.h"

# define	SIGRTN_NOERR	0
# define	SIGRTN_NOTFND	1
# define	SIGRTN_EXIT	2

typedef	int	(*t_builtin_func)(t_cmd *cmd, t_system *sys);
typedef int	(*t_launcher_func)(t_cmd *cmd, t_system *sys);

typedef struct		s_builtin
{
  char			*cmd;
  t_builtin_func	func;
  char			fork;
}			t_builtin;

typedef struct		s_launcher
{
  char			sym;
  t_launcher_func	func;
}			t_launcher;

typedef struct		s_history
{
  struct s_history	*prev;
  char			*cmd;
  struct s_history	*next;
}			t_history;

typedef struct		s_alias
{
  char			*nickname;
  char			**args;
  struct s_alias	*next;
  struct s_alias	*previous;
}			t_alias;

int		process_cmdlist(t_cmd *cmd, t_system *sys);
int		launch_cmd(t_cmd *cmd, t_system *sys);
int		launch_pipe(t_cmd *cmd, t_system *sys);
int		launch_redir_right(t_cmd *cmd, t_system *sys);
int		launch_redir_left(t_cmd *cmd, t_system *sys);
int		launch_binary(t_cmd *cmd, t_system *sys);

/****************\
|* Builtin list *|
\****************/

int		builtin_launch(t_cmd *cmd, t_system *sys);
int		builtin_exit(t_cmd *cmd, t_system *sys);
int		builtin_env(t_cmd *cmd, t_system *sys);
int		builtin_setenv(t_cmd *cmd, t_system *sys);
int		builtin_unsetenv(t_cmd *cmd, t_system *sys);
int		builtin_chdir(t_cmd *cmd, t_system *sys);
int		builtin_alias(t_cmd *cmd, t_system *sys);
int		builtin_unalias(t_cmd *cmd, t_system *sys);
int		builtin_heredoc(t_cmd *cmd, t_system *sys);
int		builtin_history(t_cmd *cmd, t_system *sys);

/*********************\
|* Builtin specifics *|
\*********************/

/*
** chdir
*/
char		*chdir_parent(char *path);
char		*chdir_enter(char *path, char *next);
char		*chdir_newpath(char *path, char *modifier);
char		*chdir_buildbase(char **env, char *path, char *mod);
void		chdir_oldpwd(t_system *sys);

/*
** history
*/
void		fill_history(t_system *av);
t_history	*stack_history(t_history *history, char *line);
void		destroy_history(t_system *av);

/*
** alias
*/
char		*get_matched_alias(char *cmd, t_alias *alias);
int		alias_print(t_alias **alias);
void		destroy_alias(t_alias *alias);

/*******************\
|* Launcher helper *|
\*******************/

pid_t		launch_pipe_in(t_cmd *cmd, t_system *sys, int pfd[2]);
pid_t		launch_pipe_out(t_cmd *cmd, t_system *sys, int pfd[2]);
pid_t		launch_redir_in(t_cmd *c, t_system *s, int pfd[2], int owr);
pid_t		launch_redir_out(t_cmd *cmd, t_system *sys, int pfd[2]);
pid_t		launch_redir_heredoc(t_cmd *cmd, t_system *sys, int pfd[2]);
void		redir_io(int fd_in, int fd_out);

#endif		/* BUILTIN_H_ */
