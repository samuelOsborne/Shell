/*
** prompt.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Jun  4 19:12:16 2016 Lucas Villeneuve
** Last update Sat Jun  4 19:20:17 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "42sh.h"

static char	*g_prompt;

void	ini_prompt()
{
  g_prompt = strdup("-->");
}

void		init_all(t_all *all)
{
  if (all->tty == 1)
    my_putstr(g_prompt);
  if ((all->tree = calloc(1, sizeof(t_tree))) == NULL)
    error_malloc();
  all->path = my_str_to_wordtab(my_getenv(all->env.tab, "PATH="), ':');
}

int		read_in_rc(t_all *all, char *s)
{
  t_alias	*new;

  if (!s[0] || s[0] == '#')
    return (1);
  if (strncmp("prompt=", s, 7) == 0 && all->lock_prompt == 0)
    {
      free(prompt);
      g_prompt = get_prompt(s);
      all->lock_prompt++;
    }
  if (is_alias_valid(s) != -1)
    {
      if ((new = malloc(sizeof(t_alias))) == NULL)
	error_malloc();
      new->alias = get_alias(s);
      new->cmd = get_alias_cmd(s);
      new->next = NULL;
      put_alias_in_list(all, new);
    }
  return (0);
}

void	sig_finder(int sig)
{
  if (sig == SIGINT)
    {
      my_putstr("\b\b  \n");
      my_putstr(g_prompt);
    }
}

void	free_prompt()
{
  free(g_prompt);
}
