/*
** merge_alias.c for 42sh in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Tue May 24 12:24:45 2016 escorn_t
** Last update Fri Jun  3 19:05:19 2016 escorn_t
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char		*get_first_cmd(char *cmd)
{
  char		*res;
  int		i;

  i = 0;
  if ((res = malloc(strlen(cmd) + 1)) == NULL)
    error_malloc();
  while (cmd[i] && cmd[i] != ' ')
    {
      res[i] = cmd[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

char		*alias_in_cmd(char *cmd, char *alias)
{
  char		*res;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((res = malloc(strlen(alias) + strlen(cmd) + 1)) == NULL)
    error_malloc();
  while (alias[i])
    {
      res[i] = alias[i];
      i++;
    }
  while (cmd[j] && cmd[j] != ' ')
    j++;
  while (cmd[j])
    res[i++] = cmd[j++];
  res[i] = 0;
  free(cmd);
  return (res);
}

char		*merge_alias(t_all *all, char *cmd)
{
  t_alias	*tmp;
  char		*first;

  first = get_first_cmd(cmd);
  tmp = all->alias;
  while (tmp)
    {
      if (strcmp(tmp->alias, first) == 0)
	{
	  cmd = alias_in_cmd(cmd, tmp->cmd);
	  free(first);
	  return (cmd);
	}
      tmp = tmp->next;
    }
  free(first);
  return (cmd);
}
