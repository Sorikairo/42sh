/*
** new_buffer.c for new_buffer in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 17:13:21 2014 Barneaud Viveka
** Last update Sat May 24 11:44:38 2014 Barneaud Viveka
*/

#include	<stdlib.h>
#include	<dirent.h>
#include	<string.h>
#include	<tutils.h>
#include	"system.h"
#include	"autocompletion.h"

char		*get_filename(t_buf_parts bufp)
{
  char		*filename;
  DIR		*dir;
  struct dirent	*dirp;

  if ((dir = opendir(bufp.path)) == NULL)
    return ("Error\n");
  while ((dirp = readdir(dir)) != NULL)
    {
      if (strncmp(dirp->d_name, bufp.start, utl_strlen(bufp.start)) == 0)
	{
	  filename = strdup(dirp->d_name);
	  if (is_dir(bufp, filename) == 0)
	    filename = realloc_and_cat(filename, "/");
	}
    }
  free(dir);
  return (filename);
}

int		remove_space(char **nbuf)
{
  if (utl_strlen(*nbuf) > 1 &&
      ((*nbuf)[utl_strlen(*nbuf) - 1] == ' ' ||
       (*nbuf)[utl_strlen(*nbuf) - 1] == '\t'))
    {
      (*nbuf)[utl_strlen(*nbuf) - 1] = '\0';
      return (1);
    }
 return (0);
}

char		*ctn_buffer(char *ctn, char *filename, int i)
{
  int		j;

  j = 0;
  if (filename == NULL)
    return (ctn);
  while (filename[i] != '\0')
    {
      if (filename[i] == ' ')
	ctn[j++] = '\\';
      ctn[j++] = filename[i++];
    }
  return (ctn);
}

char		*new_buffer(t_buf_parts bufp, t_system *av)
{
  char		*nbuf;
  char		*ctn;
  char		*filename;
  int		i;

  nbuf = strdup(bufp.before_cursor);
  if (nbuf == NULL)
    return (utl_strcpy("\0"));
  remove_space(&nbuf);
  filename = get_filename(bufp);
  if ((ctn = malloc_str(sizeof(*ctn) * (utl_strlen(filename) * 2))) == NULL)
    return (utl_strcpy("exit\n"));
  i = 0;
  while (bufp.start[i] != '\0')
    i++;
  ctn = ctn_buffer(ctn, filename, i);
  xfree(filename);
  nbuf = realloc_and_cat(nbuf, ctn);
  nbuf = realloc_and_cat(nbuf, bufp.after_cursor);
  g_pos += utl_strlen(ctn);
  free(ctn);
  return (nbuf);
}
