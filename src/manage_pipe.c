/*
** tmp_pipe2.c for lol in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon May 30 16:39:33 2016 Lucas Villeneuve
** Last update Wed Jun  1 10:24:32 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "42sh.h"

void	dup_and_close(int dup, int duped)
{
  dup2(dup, duped);
  close(dup);
}

void	manage_start_right(t_fd *st_end, t_pipe *cmd, t_all *all)
{
  if (strcmp(cmd[0].tab[0], ">") == 0 || strcmp(cmd[0].tab[0], ">>") == 0)
    {
      if (strcmp(cmd[0].tab[0], ">") == 0)
	{
	  if ((st_end->end = open(cmd[1].tab[0],
			  O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
	    exit(1);
	}
      else if (strcmp(cmd[0].tab[0], ">>") == 0)
	if ((st_end->end = open(cmd[1].tab[0],
			O_WRONLY | O_CREAT | O_APPEND, 0664)) == -1)
	  exit(1);
      dup_and_close(st_end->end, 1);
      my_exec_pipe(cmd[2].tab, all->path, &all->env, all);
    }
}

void	manage_start_start(t_fd *st_end, t_pipe *cmd, int j)
{
  if (strcmp(cmd[j].tab[0], "<") == 0)
    {
      if ((st_end->start = open(cmd[j + 1].tab[0], O_RDONLY)) == -1)
	{
	  my_put_err("Can't open the file\n");
	  exit(1);
	}
      dup_and_close(st_end->start, 0);
      st_end->mode = 1;
    }
  else if (strcmp(cmd[j + 1].tab[0], "<") == 0)
    {
      if ((st_end->start = open(cmd[j + 2].tab[0], O_RDONLY)) == -1)
	{
	  my_put_err("Can't open the file\n");
	  exit(1);
	}
      dup_and_close(st_end->start, 0);
    }
  else if (st_end->start != 0)
    dup_and_close(st_end->start, 0);
}

void	manage_start_pipe(t_fd *st_end, t_pipe *cmd, int j, t_all *all)
{
  if (st_end->start == 0)
    {
      manage_start_right(st_end, cmd, all);
      manage_start_start(st_end, cmd, j);
    }
  else
    {
      if (st_end->mode == 1)
	st_end->mode = 0;
      else
	dup_and_close(st_end->start, 0);
    }
}

void	manage_end_pipe(int end, t_pipe *cmd, int j)
{
  if (end != 1 && strcmp(cmd[j + 1].tab[0], "<") != 0)
    {
      if (strcmp(cmd[j + 1].tab[0], ">") == 0)
	{
	  if ((end = open(cmd[j + 2].tab[0],
			  O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
	    exit(1);
	}
      else if (strcmp(cmd[j + 1].tab[0], ">>") == 0)
	if ((end = open(cmd[j + 2].tab[0],
			O_WRONLY | O_CREAT | O_APPEND, 0664)) == -1)
	  exit(1);
      dup2(end, 1);
      close(end);
    }
}
