/*
** wait_proc.c for 42sh in /home/fourri_l/Projects/PSU_2013_42sh
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed May 21 13:00:41 2014 Laurent Fourrier
** Last update Sat May 24 16:38:49 2014 Laurent Fourrier
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <tio.h>
#include "system.h"
#include "builtin.h"
#include "line_editor.h"

/*
** Signal message list from GNU C Library
** Some of these signals are never actually returned at exit, but they are in
** the list anyway. Go and deal with it.
*/
t_sigmsg	g_sigmsg[] =
  {
    {SIGHUP, "Hangup"},
    {SIGINT, "Interrupt"},
    {SIGQUIT, "Quit"},
    {SIGILL, "Illegal instruction"},
    {SIGTRAP, "Trace trap"},
    {SIGABRT, "Abort"},
    {SIGIOT, "IOT trap"},
    {SIGBUS, "BUS error"},
    {SIGFPE, "Floating-point exception"},
    {SIGKILL, "Kill"},
    {SIGUSR1, "User-defined signal 1"},
    {SIGSEGV, "Segmentation violation"},
    {SIGUSR2, "User-defined signal 2"},
    {SIGPIPE, "Broken pipe"},
    {SIGALRM, "Alarm clock"},
    {SIGTERM, "Termination"},
    {SIGSTKFLT, "Stack fault"},
    {SIGCHLD, "Child status has changed"},
    {SIGCONT, "Continue"},
    {SIGSTOP, "Stop"},
    {SIGTSTP, "Keyboard stop"},
    {SIGTTIN, "Background read from tty"},
    {SIGTTOU, "Background write to tty"},
    {SIGURG, "Urgent condition on socket"},
    {SIGXCPU, "CPU limit exceeded"},
    {SIGXFSZ, "File size limit exceeded"},
    {SIGVTALRM, "Virtual alarm clock"},
    {SIGPROF, "Profiling alarm clock"},
    {SIGWINCH, "Window size change"},
    {SIGIO, "I/O now possible"},
    {SIGPWR, "Power failure restart"},
    {SIGSYS, "Bad system call"},
    {0, NULL}
  };

static void	print_sigmsg(int signal, int coredump)
{
  int		it;

  it = 0;
  while (g_sigmsg[it].sig)
    {
      if (g_sigmsg[it].sig == signal)
	{
	  write_str(g_fstdout, g_sigmsg[it].msg);
	  if (coredump)
	    write_str(g_fstdout, " (core dumped)");
	  write_char(g_fstdout, '\n');
	  flush_file(g_fstdout);
	}
      it++;
    }
}

void		wait_proc(t_system *sys, pid_t pid)
{
  int		status;

  signal(SIGINT, SIG_IGN);
  signal(SIGWINCH, SIG_IGN);
  waitpid(pid, &status, 0);
  print_sigmsg(WTERMSIG(status), WIFSIGNALED(status) && WCOREDUMP(status));
  sys->last_rtn = WIFEXITED(status) ? WEXITSTATUS(status) :
    128 + WTERMSIG(status);
  signal(SIGINT, &use_signal);
  signal(SIGWINCH, &use_signal);
}
