/*
** cmdparser.h for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Feb  4 11:11:34 2014 Laurent Fourrier
** Last update Wed May 28 13:49:40 2014 Laurent Fourrier
*/

#ifndef		CMDPARSER_H_
# define	CMDPARSER_H_

# include	<tsys.h>
# include	"system.h"

# define	SYM_NONE	0
# define	SYM_SEMICOLON	1
# define	SYM_PIPE	2
# define	SYM_REDIR_RGT	3
# define	SYM_REDIR_LFT	4
# define	SYM_REDIR_ORGT	5
# define	SYM_REDIR_OLFT	6
# define	SYM_BIN_AND	7
# define	SYM_BIN_OR	8

# define	COMMENT_CHAR	'#'

typedef struct	s_sym
{
  char		*str;
  int		sym;
  t_bool	chain;
}		t_sym;

typedef struct	s_cmd
{
  char		*cmd;
  char		*path;
  char		**args;
  int		nxtsym;
  struct s_cmd	*next;
}		t_cmd;

/*
** Main parsing funcions
*/
t_cmd		*cmd_parse(char *line, t_system *);
t_cmd		*cmd_parse_next(char *line, t_system *, int sym);

/*
** Command list management functions
*/
void		cmd_transform(t_cmd *cmd, t_system *system);
void		cmd_get_paths(t_cmd *cmd, char *path);
void		destroy_cmdlist(t_cmd *list);
void		remove_nxtcmd(t_cmd *cmd);
t_cmd		*get_lastcmd(t_cmd *cmd);

/*
** Symbol related functions
*/
int		get_sym(char *str);
t_bool		is_chainloadable(int sym);
char		*skip_sym(char *str);
int		get_next_sym(char *cmd);

/*
** Utils functions
*/
char		*malloc_str(int size);
char		*str_before_wcard(char *cmd);
char		*str_after_wcard(char *cmd);
int		my_strendcmp(char *s1, char *s2);
char		**add_files_to_args(char **args, char **files, int pos);
void		check_if_wildcard(t_cmd *cmd, t_system *sys);

#endif		/* CMDPARSER_H_ */
