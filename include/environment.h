/*
** environment.h for minishell2 in /home/fourri_l/Projects/PSU_2013_minishell2
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Feb 24 22:19:07 2014 Laurent Fourrier
** Last update Sat May 24 16:26:19 2014 Barneaud Viveka
*/

#ifndef		ENVIRONMENT_H_
# define	ENVIRONMENT_H_

/*
** Environment functions
*/

char		**env_check(char **env);
char		**env_cpy(char **env);

char		**env_set(char **env, char *var, char *value);
char		*env_get(char **env, char *var);
int		env_get_addr(char **env, char *var);
char		**env_delete(char **env, char *var);

/*
** Environment utils functions
*/

char		env_print(char **env);
char		*env_parsevar(char **env, char *str);

char		*create_path(char **env);

#endif		/* ENVIRONMENT_H_ */
