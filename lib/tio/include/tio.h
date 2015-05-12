/*
** tio.h for tio in /home/fourri_l/Projects/lib/tio
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Dec  9 17:10:46 2013 Laurent Fourrier
** Last update Thu Mar 20 14:28:13 2014 Laurent Fourrier
*/

#ifndef TIO_H_
# define TIO_H_

# define FILE_BUFSIZE	1024

# define FILE_R		0x01
# define FILE_W		0x02
# define FILE_RW	0x03
# define FILE_NOPREREAD	0x04

typedef struct	s_file
{
  char		buf[FILE_BUFSIZE];
  int		fd;
  int		mode;
  int		buf_it;
  int		bytes_read;
}		t_file;

t_file		*g_fstdin;
t_file		*g_fstdout;
t_file		*g_fstderr;

/*
** File management
*/
t_file	*open_file(char *path, int mode);
t_file	*fd_open_file(int fd, int mode);
void	flush_file(t_file *file);
void	close_file(t_file *file);
int	is_readable(t_file *file);
int	is_writable(t_file *file);

/*
** File reading
*/
char	read_char(t_file *file);
void	*read_data(t_file *file, void *data, int size);
char	*read_line(t_file *file);
char	*read_word(t_file *file, char *seps);

/*
** File writing
*/
void	write_char(t_file *file, char c);
void	write_data(t_file *file, void *data, int size);
void	write_str(t_file *file, char *str);

/*
** System functions
*/
void	open_fstd();
void	close_fstd();
int	get_openflags(int mode);

#endif
