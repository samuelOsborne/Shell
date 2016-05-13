/*
** builtins.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 13 17:32:16 2016 Lucas Villeneuve
** Last update Fri May 13 17:40:22 2016 Lucas Villeneuve
*/

#include <string.h>
#include "42sh.h"

int	my_cd(char **cmd, t_all *all)
{
  if (strcmp(cmd[0], "cd") != 0)
    return (0);
  return (1);
}

int	my_exit_and_env(char **cmd, t_all *all)
{
  if (strcmp(cmd[0], "exit") == 0)
    return (1);
  else if (strcmp(cmd[0], "env") == 0)
    return (1);
  return (0);
}

int	my_setenv(char **cmd, t_all *all)
{
  if (strcmp(cmd[0], "setenv") != 0)
    return (0);
  return (1);
}

int	my_unsetenv(char **cmd, t_all *all)
{
  if (strcmp(cmd[0], "unsetenv") != 0)
    return (0);
  return (1);
}
