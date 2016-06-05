/*
** tmp_pipe.c for lol in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon May 30 15:37:06 2016 Lucas Villeneuve
** Last update Sun Jun  5 14:13:18 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "42sh.h"

void	manage_mode_pipe(t_pipe *cmd, t_fd *st_end, int j, t_all *all)
{
  if (cmd[j + 3].tab != NULL)
    manage_end_pipe(st_end->end, cmd, j + 2);
  if (strcmp(cmd[j + 2].tab[0], "|") != 0)
    my_exec_pipe(cmd[j + 2].tab, all->path, &all->env, all);
}

int	fork_exec_pipe(t_fd *st_end, t_pipe *cmd, int j, t_all *all)
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == -1)
    return (1);
  else if (pid == 0)
    {
      manage_start_pipe(st_end, cmd, j, all);
      if (st_end->mode == 0)
      	{
      	  manage_end_pipe(st_end->end, cmd, j);
      	  my_exec_pipe(cmd[j].tab, all->path, &all->env, all);
      	}
      else
	manage_mode_pipe(cmd, st_end, j, all);
    }
  else
    {
      wait(&status);
      error_status(status, all);
      if (all->status != 0)
	return (all->status);
    }
  return (0);
}

void	end_loop_pipe(t_fd st_end, t_pipe *cmd, t_all *all, int j)
{
  if (st_end.start != 0)
    dup2(st_end.start, 0);
  if (strcmp(cmd[j - 1].tab[0], "|") == 0)
    my_exec_pipe(cmd[j].tab, all->path, &all->env, all);
  else
    exit(0);
}

void		my_loop_pipe(char **tab, t_all *all, t_pipe *cmd)
{
  int		nb_pipe;
  int		fd[2];
  int		i;
  int		j;
  int		ret;
  t_fd		st_end;

  nb_pipe = count_nb_pipe(tab);
  st_end.start = 0;
  st_end.mode = 0;
  j = 0;
  i = -1;
  while (++i < nb_pipe)
    {
      if (pipe(fd) < 0)
	exit(1);
      st_end.end = fd[1];
      ret = fork_exec_pipe(&st_end, cmd, j, all);
      if (ret == 1 || ret == 3)
	error_command_pipe(cmd[j].tab[0], ret);
      close(fd[1]);
      st_end.start = fd[0];
      j += 2;
    }
  end_loop_pipe(st_end, cmd, all, j);
}
