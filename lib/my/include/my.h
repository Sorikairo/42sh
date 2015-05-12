/*
** my.h for minishell in /home/fouhet_k/rendu/PSU_2013_minishell2/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Mar  6 13:28:11 2014 Kevin Fouhety
** Last update Thu Mar  6 13:28:12 2014 Kevin Fouhety
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int     my_putchar(char);
int     my_isneg(int);
void    my_put_nbr(int);
void    my_swap(char, char);
void    my_putstr(char *);
int     my_strlen(char *);
int     my_getnbr(char *);
void    my_sort_int_tab(int *, int);
int     my_power_rec(int, int);
int     my_square_root(int);
int     my_is_prime(int);
int     my_find_prime_sup(int);
char    *my_strcpy(char *, char *);
char    *my_strncpy(char *, char *, int);
char    *my_revstr(char *);
char    *my_strstr(char *, char *);
int     my_strcmp(char *, char *);
int     my_strncmp(char *, char *, int);
char    *my_strupcase(char *);
char    *my_strlowcase(char *);
char    *my_strcapitalize(char *);
int     my_str_isalpha(char *);
int     my_str_isnum(char *);
int     my_str_islower(char *);
int     my_str_isupper(char *);
int     my_str_isprintable(char *);
int     my_showstr(char *);
int     my_showmem(char *, int);
char    *my_strcat(char *, char *);
char    *my_strncat(char *, char *, int);
char    *my_strlcat(char *, char *, int);
int     my_printf(const char *, ...);

#endif /* !MY_H_ */
