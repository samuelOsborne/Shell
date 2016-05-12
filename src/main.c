/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Thu May 12 18:03:00 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

int		main_loop(t_env *env)
{
  t_tree	*tree;
  int		i;

  while (42)
    {
      my_putstr("-->");
      if ((tree = calloc(1, sizeof(t_tree))) == NULL)
	error_malloc();
      tree->cmd = get_next_line(0);
      create_tree(tree);
      i = 0;
      while (tree->next[i] != NULL)
	{
	  tree->next[i]->cmd = epurstr(tree->next[i]->cmd);
	  my_simple_exec(my_str_to_wordtab(tree->next[i]->cmd, ' '), NULL, env);
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
  main_loop(&env);
  return ;
}

int		main(int argc, char **argv, char **env)
{
  (void)argc;
  (void)argv;
  if (!env[0])
    my_put_err("Env is NULL\n");
  ini_shell(env);
  return (0);
}
