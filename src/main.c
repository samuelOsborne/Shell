/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Thu Jun  2 11:57:54 2016 escorn_t
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

void		init_all(t_all *all)
{
  if (all->tty == 1)
    my_putstr("-->");
  if ((all->tree = calloc(1, sizeof(t_tree))) == NULL)
    error_malloc();
  all->path = my_str_to_wordtab(my_getenv(all->env.tab, "PATH="), ':');
  if ((all->tree->cmd = get_next_line(0)) == NULL)
    return ;
}

void		main_loop(t_all *all)
{
  int		i;
  int		j;

  while (42)
    {
      init_all(all);
      create_tree(all->tree);
      i = 0;
      while (all->tree->next[i] != NULL)
	{
	  j = 0;
	  while (all->tree->next[i]->next[j] != NULL)
	    {
	      if (launch_condition(all, all->tree->next[i]->spec, j) == 0)
                launch_exec(all->tree->next[i]->next[j], all);
	      j++;
	    }
	  i++;
	}
      free_path(all->path);
      free_tree(all->tree);
    }
}

void		ini_shell(char **ae)
{
  t_all		all;

  all.env.size = 0;
  while (ae[all.env.size] != NULL)
    all.env.size++;
  all.env.tab = create_env(ae, all.env.size);
  all.tty = isatty(0);
  all.cd.old = my_getenv(all.env.tab, "OLDPWD=");
  all.cd.pwd = my_getenv(all.env.tab, "PWD=");
  if (signal(SIGINT, sig_finder) == SIG_ERR)
    return ;
  main_loop(&all);
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
