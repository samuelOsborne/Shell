/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
**
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
**
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Sun Jun  5 15:07:53 2016 Samuel
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

void		exec_process(t_all *all)
{
  int		i;
  int		j;

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
  free_tree(all->tree);
}

void		main_loop(t_all *all)
{
  while (42)
    {
      init_all(all);
      if ((all->tree->cmd = epurstr(get_next_line(0))) == NULL)
	return ;
      all->status = 0;
      if (parse_for_errors(all->tree->cmd) != -1)
	exec_process(all);
      free_path(all->path);
      free(all->tree->next);
      free(all->tree->cmd);
      free(all->tree);
    }
}

int		ini_shell(char **ae)
{
  t_all		all;

  all.env.size = 0;
  while (ae[all.env.size] != NULL)
    all.env.size++;
  all.env.tab = create_env(ae, all.env.size);
  all.tty = isatty(0);
  all.cd.old = my_getenv(all.env.tab, "OLDPWD=");
  all.cd.pwd = my_getenv(all.env.tab, "PWD=");
  all.status = 0;
  all.lock_prompt = 0;
  init_rc(&all);
  if (signal(SIGINT, sig_finder) == SIG_ERR)
    return (1);
  main_loop(&all);
  return (all.status);
}

int		main(__attribute__((unused))int argc,
		     __attribute__((unused))char **argv,
		     char **env)
{
  return (ini_shell(env));
}
