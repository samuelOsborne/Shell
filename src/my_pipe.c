/*
** my_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue May 24 10:34:19 2016 Lucas Villeneuve
** Last update Tue May 31 10:54:13 2016 Lucas Villeneuve
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42sh.h"

/* void	fork_exec_pipe(t_fd st_end, t_pipe *cmd, int j, t_all *all) */
/* { */
/*   pid_t	pid; */
/*   int	status; */

/*   if ((pid = fork()) == -1) */
/*     return ; */
/*   else if (pid == 0) */
/*     { */
/*       /\* if (j == 0) *\/ */
/*       /\* 	manage_start_redir(st_end.start, st_end.end, cmd, all); *\/ */
/*       manage_start_pipe(st_end.start, cmd, j); */
/*       manage_end_pipe(st_end.end, cmd, j); */
/*       my_exec_pipe(cmd[j].tab, all->path, &all->env); */
/*     } */
/*   else */
/*     { */
/*       wait(&status); */
/*       if (status == 11 || status == 139 || status == SIGSEGV) */
/* 	my_put_err("Segmentation fault\n"); */
/*     } */
/* } */

/* void	end_loop_pipe(t_fd st_end, t_pipe *cmd, t_all *all, int j) */
/* { */
/*   if (st_end.start != 0) */
/*     dup2(st_end.start, 0); */
/*   if (strcmp(cmd[j - 1].tab[0], "|") == 0) */
/*     my_exec_pipe(cmd[j].tab, all->path, &all->env); */
/*   exit(0); */
/* } */

/* void		my_loop_pipe(char **tab, t_all *all, t_pipe *cmd) */
/* { */
/*   int		nb_pipe; */
/*   int		fd[2]; */
/*   int		i; */
/*   int		j; */
/*   t_fd		st_end; */

/*   nb_pipe = count_nb_pipe(tab); */
/*   st_end.start = 0; */
/*   j = 0; */
/*   i = -1; */
/*   while (++i < nb_pipe) */
/*     { */
/*       if (pipe(fd) < 0) */
/*   	return ; */
/*       st_end.end = fd[1]; */
/*       fork_exec_pipe(st_end, cmd, j, all); */
/*       close(fd[1]); */
/*       st_end.start = fd[0]; */
/*       j += 3; */
/*     } */
/*   end_loop_pipe(st_end, cmd, all, j); */
/* } */

void		my_pipe(char **tab, t_all *all)
{
  int		status;
  pid_t		pid;
  t_pipe	*cmd;

  if ((pid = fork()) == -1)
    return ;
  else if (pid == 0)
    {
      if ((cmd = create_cmd_pipe(tab)) == NULL)
	exit(1);
      my_loop_pipe(tab, all, cmd);
      free(cmd);
      exit(0);
    }
  else
    {
      wait(&status);
      if (status == 11 || status == 139 || status == SIGSEGV)
	my_put_err("Segmentation fault\n");
    }
}
