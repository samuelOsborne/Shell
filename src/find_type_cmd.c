/*
** find_type_cmd.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 13 17:15:58 2016 Lucas Villeneuve
** Last update Fri May 13 17:41:50 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	check_builtin(char **cmd, t_all *all)
{
  int	(*tab[4])(char **cmd, t_all *all);
  char	*string;
  int	i;

  if ((string = calloc(5, sizeof(char))) == NULL)
    error_malloc();
  strcpy(string, "cesu");
  i = 0;
  tab[0] = &my_cd;
  tab[1] = &my_exit_and_env;
  tab[2] = &my_setenv;
  tab[3] = &my_unsetenv;
  while (i < 4)
    {
      if (cmd[0][0] == string[i])
	return (tab[i](cmd, all));
      i++;
    }
  return (0);
}

/* int	check_simple_exec(char **tab, t_all *all) */
/* { */
/* } */

void	find_type_cmd(char **tab, t_all *all)
{
  if (check_builtin(tab, all) == 1)
    return ;
  my_simple_exec(tab, all->path, &all->env);
}
