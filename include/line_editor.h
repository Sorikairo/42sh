/*
** minishell.h for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:27:04 2014 Kevin Fouhety
** Last update Sat May 24 18:17:13 2014 Barneaud Viveka
*/

#ifndef		LINE_EDITOR_H_
# define	LINE_EDITOR_H_

# include	<unistd.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/wait.h>
# include	<term.h>
# include	<curses.h>
# include	<signal.h>
# include	"system.h"
# include	"struct.h"
# include	"builtin.h"
# include	"my_printf.h"

extern int	g_pos;
extern char	*g_nbuf;

# define	NB_READ 4

/* promp */

void		my_clear_window();
int		my_comp(char *, char *);
char		*save_the_line();
void		restor_cursor_pos();

/* Term */

char		*take_term(char **);
char		*my_strcat_term(char *, char *, int);
void		my_free_term(t_system *, t_term *, char *);
int		my_free_term_bis(t_system *, t_term *, char *);
int		number_carac(int);
char		*print_revers(char);
void		restor_cursor_pos();
void		print_promp_buffer(char *);
void		print_promp_buffer_del(char *, char *);

/* set Term */

t_term		*init_struct_term();
t_term		*my_set_termio(t_term *);
void		put_read_term(t_term *);
void		put_old_term(t_term *);
void		my_free_struct(t_term *);

/* work on line */

char		*my_read_inf(t_system *, t_term *);
char		*work_on_nbuf(char *, t_system *, t_term *, char *);
char		*delet_last_char(char *, t_system *, int);
char		*delet_char(char *, t_system *, int);
char		*utl_strcpy_free(char *, char *);
int		decrease_pos(int);
int		increase_pos(int, char *);
void		rewrite(char *, int, int);
char		*buffer_one_lenth(char *, char *, t_system *);
char		*buffer_three_lenth(char *, char *, t_system *);
int		take_new_pos(char *, int, char);

/* work on history */

char		*reprint_cmd(char *, t_system *, char *);
char		*reprint_nextcmd(t_history *, int);
char		*reprint_lastcmd(t_history *, int);
int		size_list(t_history *);

/* Utility */

char		*xmalloc(int);
void		use_signal(int);
void		free_tab(char **);
void		free_dyn_sh(t_system *, char *);
int		my_print_test(int);
void		my_print_cursor();

#endif		/*LINE_EDITOR_H_ */
