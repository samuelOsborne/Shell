/*
** my_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Tue May 24 10:34:19 2016 Lucas Villeneuve
** Last update Thu Jun  2 19:39:29 2016 Lucas Villeneuve
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42sh.h"

void		my_pipe(char **tab, t_all *all)
{
  pid_t		pid;
  t_pipe	*cmd;
  int		status;

  if ((pid = fork()) == -1)
    return ;
  else if (pid == 0)
    {
      if ((cmd = create_cmd_pipe(tab)) == NULL)
	exit(1);
      my_loop_pipe(tab, all, cmd);
      free(cmd);
    }
  else
    {
      wait(&status);
      all->status = WTERMSIG(status);
      if (all->status == SIGSEGV)
	my_put_err("Segmentation fault (core dumped)\n");
      else if (all->status == SIGFPE)
	my_put_err("Floating exception (core dumped)\n");
      all->status = WEXITSTATUS(status);
    }
}
