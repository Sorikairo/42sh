/*
** tutils.h for tutils in /home/fourri_l/Projects/lib/tutils
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Dec  3 13:37:31 2013 Laurent Fourrier
** Last update Tue Apr 22 17:05:04 2014 Laurent Fourrier
*/

#ifndef TUTILS_H_
#define TUTILS_H_

/*
** Word arrays
*/
int	is_wordarr_separator(char c, char *seps);
int	get_next_word_len(char *str, char *seps);
char	*get_next_word(char *str, char *seps, char **next);
char	**str_to_wordarr(char *str, char *seps);
void	destroy_wordarr(char **wordarr);
int	get_wordarr_len(char **wordarr);
char	**wordarr_cpy(char **wordarr);

/*
** Formated word arrays
*/
int	fmt_get_next_word_len(char *str, char *seps, char **next);
char	*fmt_get_next_word(char *str, char *seps, char **next);
char	**fmt_str_to_wordarr(char *str, char *seps);

/*
** String info
*/
int	utl_strlen(char *str);
int	utl_strcmp(char	*first, char *second);
int	utl_strncmp(char *first, char *second, int n);
int	utl_strisnbr(char *str);
int	utl_strisvalid(char *str, char *valids);

/*
** String operation
*/
char	*utl_strcpy(char *str);
char	*utl_strncpy(char *str, int n);
char	*utl_strcat(char *dst, char *str);
char	*utl_strncat(char *dst, char *str, int n);
char	*utl_strcatc(char *dst, char c);
char	*utl_strdelc(char *str, char *dels);

/*
** String misc.
*/
int	utl_atoi(char *str);
char	*utl_itoa(int nbr);
double	utl_atod(char *str);

/*
** Pseudo random number generator
*/
int	utl_rand_memory(int range);
int	utl_rand_vneumann(int seed);

#endif
