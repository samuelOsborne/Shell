/*
** manage_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu May 26 12:22:09 2016 Lucas Villeneuve
** Last update Thu May 26 12:42:41 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "42sh.h"

void	manage_start_pipe(int start, t_pipe *cmd, int j)
{
  if (strcmp(cmd[j + 1].tab[0], "<") == 0)
    {
      if ((start = open(cmd[j + 2].tab[0], O_RDONLY)) == -1)
	{
	  my_put_err("Can't open the file\n");
	  exit(1);
	}
      dup2(start, 0);
      close(start);
    }
  else if (start != 0)
    {
      dup2(start, 0);
      close(start);
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

void	manage_dup_exec(int duped, int todup, t_pipe *cmd, t_all *all)
{
  dup2(duped, todup);
  close(duped);
  my_exec_pipe(cmd[2].tab, all->path, &all->env);
}

void	manage_start_redir(int start, int end, t_pipe *cmd, t_all *all)
{
  if (strcmp(cmd[0].tab[0], ">") == 0 || strcmp(cmd[0].tab[0], ">>") == 0)
    {
      if (strcmp(cmd[0].tab[0], ">") == 0)
	{
	  if ((end = open(cmd[1].tab[0],
			  O_WRONLY | O_CREAT | O_TRUNC, 0664)) == -1)
	    exit(1);
	}
      else if (strcmp(cmd[0].tab[0], ">>") == 0)
	if ((end = open(cmd[1].tab[0],
			O_WRONLY | O_CREAT | O_APPEND, 0664)) == -1)
	  exit(1);
      manage_dup_exec(end, 1, cmd, all);
    }
  else if (strcmp(cmd[0].tab[0], "<") == 0)
    {
      if ((start = open(cmd[1].tab[0], O_RDONLY)) == -1)
	{
	  my_put_err("Can't open the file\n");
	  exit(1);
	}
      manage_dup_exec(start, 0, cmd, all);
    }
}
