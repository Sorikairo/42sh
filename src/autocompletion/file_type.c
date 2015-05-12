/*
** file_type.c for file_type in /home/barnea_v/rendu/PSU_2013_42sh
** 
** Made by Barneaud Viveka
** Login   <barnea_v@epitech.net>
** 
** Started on  Tue May  6 16:27:50 2014 Barneaud Viveka
** Last update Fri May 16 11:36:25 2014 Barneaud Viveka
*/

#include	<sys/stat.h>
#include	"autocompletion.h"

char		*my_strcat_file(char *path, char *file)
{
  char		*fname;
  int		i;
  int		j;

  i = 0;
  j = my_strlen(path) + 1;
  if ((fname = malloc_str(sizeof(*fname) * (j + my_strlen(file) + 2))) == NULL)
    return (NULL);
  if (path == NULL || file == NULL)
    return (NULL);
  while (path[i] != '\0')
    {
      fname[i] = path[i];
      i++;
    }
  fname[i] = '/';
  i = 0;
  while (file[i] != '\0')
    fname[j++] = file[i++];
  fname[j] = '\0';
  return (fname);
}

int		is_dir(t_buf_parts bufp, char *file)
{
  struct stat	st;
  char		*full_name;

  if ((full_name = my_strcat_file(bufp.path, file)) == NULL)
    return (-1);
  if (stat(full_name, &st) == -1)
    return (-1);
  free(full_name);
  if (S_ISDIR(st.st_mode))
    return (0);
  return (1);
}

int		is_exe(t_buf_parts bufp, char *file)
{
  struct stat	st;
  char		*full_name;
  char		mode[10];

  if ((full_name = my_strcat_file(bufp.path, file)) == NULL)
    return (-1);
  if (stat(full_name, &st) == -1)
    return (-1);
  free(full_name);
  (S_ISDIR(st.st_mode)) ? (mode[0] = 'd') : (mode[0] = '-');
  (st.st_mode & S_IRUSR) ? (mode[1] = 'r') : (mode[1] = '-');
  (st.st_mode & S_IWUSR) ? (mode[2] = 'w') : (mode[2] = '-');
  (st.st_mode & S_IXUSR) ? (mode[3] = 'x') : (mode[3] = '-');
  (st.st_mode & S_IRGRP) ? (mode[4] = 'r') : (mode[4] = '-');
  (st.st_mode & S_IWGRP) ? (mode[5] = 'w') : (mode[5] = '-');
  (st.st_mode & S_IXGRP) ? (mode[6] = 'x') : (mode[6] = '-');
  (st.st_mode & S_IROTH) ? (mode[7] = 'r') : (mode[7] = '-');
  (st.st_mode & S_IWOTH) ? (mode[8] = 'w') : (mode[8] = '-');
  (st.st_mode & S_IXOTH) ? (mode[9] = 'x') : (mode[9] = '-');
  mode[10] = '\0';
  if (mode[3] == 'x' || mode[6] == 'x' || mode[9] == 'x')
    return (0);
  return (1);
}
