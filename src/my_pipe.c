/*
** my_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Tue May 24 10:34:19 2016 Lucas Villeneuve
** Last update Sun Jun  5 13:16:58 2016 Lucas Villeneuve
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
	return ;
      my_loop_pipe(tab, all, cmd);
      free(cmd);
    }
  else
    {
      wait(&status);
      error_status(status, all);
    }
}
