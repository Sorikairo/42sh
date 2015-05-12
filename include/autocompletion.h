/*
** autocompletion.h for autocompletion in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 12:58:19 2014 Barneaud Viveka
** Last update Sat May 24 11:06:54 2014 Barneaud Viveka
*/

#ifndef		AUTOCOMPLETION_H_
# define	AUTOCOMPLETION_H_

# include	"line_editor.h"

# define	CMD	0
# define	FILE	1
# define	XDIR	2

typedef struct	s_buf_parts
{
  char		*before_cursor;
  char		*after_cursor;
  char		*current_wd;
  char		*path;
  char		*start;
  int		status;
} t_buf_parts;

char		*str_before_cursor(char *nbuf, t_system *av);
char		*str_after_cursor(char *nbuf, t_system *av);
char		*current_word(char *bc);
char		*get_file_path(char *current, char **env);
char		*get_start(char *current);
char		*autocompletion(char *nbuf, t_system *av);
void		show_files(t_buf_parts bufp);
int		is_dir(t_buf_parts bufp, char *file);
char		**my_str_to_wtab(char *str, char *sep);
char		*new_buffer(t_buf_parts bufp, t_system *av);
int		count_slot(char **wtab);
int		count_slash(char *str);
int		is_command(char *req);
int		count_files(t_buf_parts bufp);
char		*malloc_str(int size);
char		**malloc_wtab(char **ptr, int size);
char		*realloc_and_cat(char *s1, char *s2);
void		show_wtab(char **wtab);
void		free_wtab(char **wtab);
char		*lowerize(char *str);
int		sort_word(char **s1, char **s2);
char		**ord_alpha(char **wtab);
void		divide_buffer(t_buf_parts *bufp, char *nbuf, t_system *av);
void		free_buf_parts(t_buf_parts *bufp);
int		is_exe(t_buf_parts bufp, char *file);
char		*completion_xdir(char *nbuf, t_buf_parts bufp, t_system *av);
int		is_xdir(t_buf_parts bufp, char *fname);
int		count_xdir(t_buf_parts bufp);
void		show_xdir(t_buf_parts bufp);
int		ask_if_show(t_buf_parts bufp);
char		*get_home_and_realloc(char **env, int size, int *count);
void		xfree(void *ptr);

#endif		/* AUTOCOMPLETION_H_ */
