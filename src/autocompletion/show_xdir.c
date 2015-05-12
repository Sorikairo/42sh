/*
** show_xdir.c for show_xdir in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Fri May 16 11:25:42 2014 Barneaud Viveka
** Last update Sun May 25 16:41:09 2014 Barneaud Viveka
*/

#include	<dirent.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	<string.h>
#include	<tutils.h>
#include	"autocompletion.h"

int		count_xdir(t_buf_parts bufp)
{
  int		k;
  DIR		*dir;
  struct dirent	*dirp;

  k = 0;
  if ((dir = opendir(bufp.path)) == NULL)
    return (-1);
  while ((dirp = readdir(dir)) != NULL)
    {
      if ((bufp.start == NULL || bufp.start[0] == '\0') ||
	  (my_strncmp(bufp.start, dirp->d_name, utl_strlen(bufp.start)) == 0))
	{
	  if (is_xdir(bufp, dirp->d_name) == 0)
	    k++;
	}
    }
  free(dir);
  return (k);
}

char		**get_all_xdir(t_buf_parts bp, DIR *dir)
{
  char		**ftab;
  struct dirent	*d;
  int		k;

  k = 0;
  if ((ftab = malloc(sizeof(*ftab) * (count_xdir(bp) + 1))) == NULL)
    return (NULL);
  while ((d = readdir(dir)) != NULL)
    {
      if (is_xdir(bp, d->d_name) == 0 && my_strcmp(d->d_name, ".") != 0 &&
	  my_strcmp(d->d_name, "..") != 0)
	{
	  ftab[k] = strdup(d->d_name);
	  if (ftab[k] == NULL)
	    return (ftab);
	  if (is_dir(bp, ftab[k]) == 0)
	    ftab[k] = realloc_and_cat(ftab[k], "/");
	  k++;
	}
    }
  ftab[k] = NULL;
  return (ftab);
}

char		**get_ctn_xdir(t_buf_parts bp, DIR *dir)
{
  char		**ftab;
  struct dirent	*d;
  int		k;

  k = 0;
  if ((ftab = malloc(sizeof(*ftab) * (count_xdir(bp) + 1))) == NULL)
    return (NULL);
  while ((d = readdir(dir)) != NULL)
    {
      if (is_xdir(bp, d->d_name) == 0)
	{
	  if (my_strncmp(bp.start, d->d_name, utl_strlen(bp.start)) == 0 &&
	      my_strcmp(d->d_name, ".") != 0 && my_strcmp(d->d_name, "..") != 0)
	    {
	      ftab[k] = strdup(d->d_name);
	      if (ftab[k] == NULL)
		return (ftab);
	      if (is_dir(bp, ftab[k]) == 0)
		ftab[k] = realloc_and_cat(ftab[k], "/");
	      k++;
	    }
	}
    }
  ftab[k] = NULL;
  return (ftab);
}

void		show_xdir(t_buf_parts bufp)
{
  DIR		*dir;
  char		**ftab;

  if ((dir = opendir(bufp.path)) == NULL)
    return;
  if (bufp.start == NULL || bufp.start[0] == '\0')
    ftab = get_all_xdir(bufp, dir);
  else
    ftab = get_ctn_xdir(bufp, dir);
  my_printf("\n");
  if (ftab == NULL)
    return;
  ftab = ord_alpha(ftab);
  if (ask_if_show(bufp) == 0)
    show_wtab(ftab);
  free(dir);
  free_wtab(ftab);
  save_the_line();
}
