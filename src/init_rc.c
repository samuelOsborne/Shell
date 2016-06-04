/*
** init_rc.c for 42sh in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Mon May 16 14:23:23 2016 escorn_t
** Last update Sat Jun  4 19:15:34 2016 Lucas Villeneuve
*/

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42sh.h"

int		rc_err_message(char *home_path)
{
  my_put_err("Failed to load .42sh_rc, ");
  my_put_err("make sure you have the rights to access ");
  my_put_err(home_path);
  my_put_err("\n");
  free(home_path);
  return (1);
}

int		first_rc(int fd, char *path)
{
  free(path);
  HEAD(fd, "# Configuration file for 42sh\n");
  HEAD(fd, "# A project by escorn_t, villen_l, ");
  HEAD(fd, "osborn_s, costa_d and brami_a\n");
  HEAD(fd, "# This file can be used to preload alias'\n");
  HEAD(fd, "# Usage = alias:\"command\"\n");
  HEAD(fd, "\nprompt=-->\n");
  return (0);
}

char		*path_rc(char *s)
{
  char		*res;
  char		*tmp;
  int		i;
  int		j;

  if (s == NULL)
    return (NULL);
  i = 0;
  j = 0;
  if ((res = malloc(strlen(s) + strlen("/.42shrc") + 1)) == NULL)
    error_malloc();
  tmp = "/.42shrc";
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
  ini_prompt();
  if ((home_path = path_rc(my_getenv(all->env.tab, "HOME="))) == NULL)
    return (1);
  if ((fd = open(home_path, O_CREAT | O_RDWR, 0644)) == -1)
    return (rc_err_message(home_path));
  if ((s = get_next_line(fd)) == NULL)
    return (first_rc(fd, home_path));
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
