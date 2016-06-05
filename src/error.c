/*
** error.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 17:00:47 2016 Lucas Villeneuve
** Last update Sun Jun  5 14:14:11 2016 Lucas Villeneuve
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "42sh.h"

void	error_malloc()
{
  my_put_err("Error malloc\n");
  exit(1);
}

int	error_pipe(char c)
{
  my_put_err("Error parsing near ");
  my_putchar_err(c);
  my_putchar_err('\n');
  return (2);
}

void	error_command_pipe(char *str, int ret)
{
  if (ret == 1)
    {
      my_put_err(str);
      my_put_err(": Command not found.\n");
    }
  exit(1);
}

void	error_status(int status, t_all *all)
{
  if (WTERMSIG(status) == SIGSEGV)
    {
      my_put_err("Segmentation fault\n");
      all->status = status;
    }
  else if (WTERMSIG(status) == SIGFPE)
    {
      my_put_err("Floating exception\n");
      all->status = status;
    }
  else
    all->status = WEXITSTATUS(status);
}
