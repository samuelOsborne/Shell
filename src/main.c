/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Thu May 12 11:15:30 2016 escorn_t
*/

#include <stdlib.h>
#include "42sh.h"

int		main_loop()
{
  t_tree	tree;
  char		*line;
  char		**tab;

  while (42)
    {
      my_putstr("-->");
      line = epurstr(get_next_line(0));
      tab = my_str_to_wordtab(line, ';');
      if (create_tree(&tree, tab) == -1)
	return (-1);
      free_tab(tab);
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
