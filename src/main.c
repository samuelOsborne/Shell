/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Wed May 11 18:24:09 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

void	main_loop()
{
  char	*line;
  char	**tab;

  while (42)
    {
      my_putstr("-->");
      line = epurstr(get_next_line(0));
      tab = my_str_to_wordtab(line, ';');
      free_tab(tab);
    }
}

void	ini_shell(char **ae)
{
  t_env	env;

  env.size = 0;
  while (ae[env.size] != NULL)
    env.size++;
  env.tab = create_env(ae, env.size);
}

int	main(int argc, char **argv, char **env)
{
  (void)argc;
  (void)argv;
  if (!env[0])
    my_putstr("Env is NULL\n");
  main_loop();
  return (0);
}
