/*
** builtins.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 13 17:32:16 2016 Lucas Villeneuve
** Last update Mon May 16 15:20:27 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

int	my_cd_builtin(char **cmd, t_all *all)
{
  (void)all;
  if (strcmp(cmd[0], "cd") != 0)
    return (0);
  return (1);
}

int	my_exit_and_env(char **cmd, t_all *all)
{
  if (strcmp(cmd[0], "exit") == 0)
    {
      if (cmd[1] == NULL)
	my_simple_exit(cmd, all);
      else
	my_advanced_exit(cmd, all, my_getnbr(cmd[1]));
    }
  else if (strcmp(cmd[0], "env") == 0)
    {
      print_env(&all->env);
      return (1);
    }
  return (0);
}

int	my_setenv_builtin(char **cmd, t_all *all)
{
  (void)all;
  if (strcmp(cmd[0], "setenv") != 0)
    return (0);
  my_setenv(cmd, &all->env);
  return (1);
}

int	my_unsetenv_builtin(char **cmd, t_all *all)
{
  (void)all;
  if (strcmp(cmd[0], "unsetenv") != 0)
    return (0);
  my_unsetenv(cmd, &all->env);
  return (1);
}
