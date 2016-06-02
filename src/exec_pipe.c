/*
** exec_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 25 16:27:43 2016 Lucas Villeneuve
** Last update Thu Jun  2 12:08:46 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

int	count_nb_pipe(char **tab)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      if (strcmp(tab[i], "|") == 0 || strcmp(tab[i], ">") == 0 ||
	  strcmp(tab[i], ">>") == 0 || strcmp(tab[i], "<") == 0 ||
	  strcmp(tab[i], "<<") == 0)
	count++;
      i++;
    }
  return (count);
}

void	my_exec_pipe(char **cmd, char **path, t_env *env, t_all *all)
{
  if (check_builtin(cmd, all) == 1)
    exit(0);
  if (cmd == NULL || cmd[0] == NULL)
    exit(1);
  if (path != NULL)
    cmd[0] = find_bin(path, cmd);
  else
    cmd[0] = find_bin_without_path(cmd);
  if (cmd[0] != NULL)
    execve(cmd[0], cmd, env->tab);
  else
    all->status = 1;
  exit(0);
}
