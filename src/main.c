/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Thu May 12 15:58:44 2016 escorn_t
*/

#include <stdio.h>
#include <stdlib.h>
#include "42sh.h"

int		main_loop()
{
  t_tree	*tree;
  int		i;

  while (42)
    {
      my_putstr("-->");
      if ((tree = malloc(sizeof(t_tree))) == NULL)
	error_malloc();
      tree->cmd = get_next_line(0);
      if (create_tree(tree) == -1)
	return (-1);
      printf("ENTRY = %s\n", tree->cmd);
      i = 0;
      while (tree->next[i] != NULL)
	{
	  printf("tab[%d] = %s\n", i, tree->next[i]->cmd);
	  i++;
	}
    }
}

void		ini_shell(char **ae)
{
  t_env		env;

  env.size = 0;
  while (ae[env.size] != NULL)
    env.size++;
  env.tab = create_env(ae, env.size);
}

int		main(int argc, char **argv, char **env)
{
  (void)argc;
  (void)argv;
  if (!env[0])
    my_put_err("Env is NULL\n");
  if (main_loop() == -1)
    return (-1);
  return (0);
}
