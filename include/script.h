/*
** script.h for 42sh in /home/fourri_l/rendu/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr 23 10:15:17 2014 Laurent Fourrier
** Last update Sat May 24 16:33:39 2014 Barneaud Viveka
*/

#ifndef		SCRIPT_H_
# define	SCRIPT_H_

# include	<tio.h>
# include	"system.h"

void		exec_rtconf(t_system *system);
void		launch_script(t_file *file, t_system *system);

#endif		/* SCRIPT_H_ */
