/*
** init_rc.c for 42sh in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Mon May 16 14:23:23 2016 escorn_t
** Last update Sat Jun  4 16:45:05 2016 escorn_t
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42sh.h"

int		rc_err_message(char *home_path)
{
  my_put_err("Failed to load .sh_rc, ");
  my_put_err("make sure you have the rights to access ");
  my_put_err(home_path);
  my_put_err("\n");
  return (1);
}

int		first_rc(int fd)
{
  write(fd, "# Configuration file for 42sh\n", 30);
  write(fd, "# A project by escorn_t, villen_l, ", 35);
  write(fd, "osborn_s, costa_d and brami_a\n", 30);
  write(fd, "# This file can be used to preload alias'\n", 42);
  write(fd, "# Usage = alias:\"short_command=original command\"\n", 49);
  write(fd, "\nprompt=-->\n", 12);
  return (1);
}

int		read_in_rc(t_all *all, char *s)
{
  t_alias	*new;

  if (!s[0] || s[0] == '#')
    return (1);
  if (strncmp("prompt=", s, 7) == 0 && all->lock_prompt == 0)
    {
      all->prompt = get_prompt(s);
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

char		*path_rc(char *s)
{
  char		*res;
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((res = malloc(strlen(s) + strlen("/.shrc") + 1)) == NULL)
    error_malloc();
  tmp = "/.shrc";
  while (s[i])
    {
      res[i] = s[i];
      i++;
    }
  while (tmp[j])
    res[i++] = tmp[j++];
  res[i] = 0;
  free(s);
  return (res);
}

int		init_rc(t_all *all)
{
  char		*home_path;
  char		*s;
  int		fd;

  all->alias = NULL;
  all->prompt = "-->";
  home_path = path_rc(my_getenv(all->env.tab, "HOME="));
  if ((fd = open(home_path, O_CREAT | O_RDWR, 0644)) == -1)
    return (rc_err_message(home_path));
  if ((s = get_next_line(fd)) == NULL)
    return (first_rc(fd));
  free(s);
  while ((s = get_next_line(fd)) != NULL)
    {
      read_in_rc(all, s);
      free(s);
    }
  close(fd);
  free(home_path);
  return (0);
}
