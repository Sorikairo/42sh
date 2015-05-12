/*
** show_files.c for show_files in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 16:04:03 2014 Barneaud Viveka
** Last update Wed May 28 10:18:26 2014 Barneaud Viveka
*/

#include	<dirent.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	<string.h>
#include	<tutils.h>
#include	"autocompletion.h"

int		count_files(t_buf_parts bufp)
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
	if (dirp->d_name[0] != '.')
	  k++;
    }
  free(dir);
  return (k);
}

int		ask_if_show(t_buf_parts bufp)
{
  char		buffer[1];

  if (bufp.status == XDIR)
    {
      if (count_xdir(bufp) < 50)
	return (0);
      my_printf("show all %d possibilities ? (y or n)\n", count_xdir(bufp));
    }
  else
    {
      if (count_files(bufp) < 50)
	return (0);
      my_printf("show all %d possibilities ? (y or n)\n", count_files(bufp));
    }
  if (read(0, buffer, 1) != -1)
    if (buffer[0] == 'y')
      return (0);
  return (1);
}

char		**get_all_files(t_buf_parts bufp, DIR *dir)
{
  char		**ftab;
  struct dirent	*dirp;
  int		k;

  k = 0;
  if ((ftab = malloc(sizeof(*ftab) * (count_files(bufp) + 1))) == NULL)
    return (NULL);
  while ((dirp = readdir(dir)) != NULL)
    {
      if (dirp->d_name[0] != '.')
      	{
	  ftab[k] = strdup(dirp->d_name);
	  if (ftab[k] == NULL)
	    return (ftab);
	  if (is_dir(bufp, ftab[k]) == 0)
	    ftab[k] = realloc_and_cat(ftab[k], "/");
	  k++;
	}
    }
  ftab[k] = NULL;
  return (ftab);
}

char		**get_ctn_files(t_buf_parts bufp, DIR *dir)
{
  char		**ftab;
  struct dirent	*dirp;
  int		k;

  k = 0;
  if ((ftab = malloc(sizeof(*ftab) * (count_files(bufp) + 1))) == NULL)
    return (NULL);
  while ((dirp = readdir(dir)) != NULL)
    {
      if (my_strncmp(bufp.start, dirp->d_name, utl_strlen(bufp.start)) == 0)
	{
	  ftab[k] = strdup(dirp->d_name);
	  if (ftab[k] == NULL)
	    return (ftab);
	  if (is_dir(bufp, ftab[k]) == 0)
	    ftab[k] = realloc_and_cat(ftab[k], "/");
	  k++;
	}
    }
  ftab[k] = NULL;
  return (ftab);
}

void		show_files(t_buf_parts bufp)
{
  DIR		*dir;
  char		**ftab;

  if ((dir = opendir(bufp.path)) == NULL)
    return;
  if (bufp.start == NULL || bufp.start[0] == '\0')
    ftab = get_all_files(bufp, dir);
  else
    ftab = get_ctn_files(bufp, dir);
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
