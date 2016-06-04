/*
** alias_list.c for 42sh in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 18 12:23:22 2016 escorn_t
** Last update Sat Jun  4 16:42:41 2016 escorn_t
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char		*get_prompt(char *s)
{
  char		*res;
  int		i;
  int		j;

  i = 7;
  j = 0;
  if (!s)
    {
      res = strdup("-->");
      return (res);
    }
  if (!s[0])
    {
      res = strdup("-->");
      return (res);
    }
  if ((res = malloc(strlen(s))) == NULL)
    error_malloc();
  while (s[i])
    res[j++] = s[i++];
  res[j] = 0;
  return (res);
}

int		is_alias_valid(char *s)
{
  int		i;

  i = 0;
  while (s[i] && s[i] != ':')
    i++;
  if (i == 0)
    return (-1);
  if (!s[i])
    return (-1);
  if (s[i + 1] != '"')
    return (-1);
  if (!s[i + 2] || s[i + 2] == '"')
    return (-1);
  i = i + 2;
  while (s[i])
    i++;
  if (s[i - 1] != '"')
    return (-1);
  return (0);
}

char		*get_alias(char *s)
{
  int		i;
  char		*res;

  i = 0;
  if ((res = malloc(strlen(s))) == NULL)
    error_malloc();
  while (s[i] != ':')
    {
      res[i] = s[i];
      i++;
    }
  res[i] = 0;
  return (res);
}

char		*get_alias_cmd(char *s)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  if ((res = malloc(strlen(s))) == NULL)
    error_malloc();
  while (s[i] != ':')
    i++;
  i = i + 2;
  while (s[i] != '"')
    res[j++] = s[i++];
  res[j] = 0;
  return (res);
}

void		put_alias_in_list(t_all *all, t_alias *new)
{
  t_alias	*tmp;

  tmp = all->alias;
  if (all->alias == NULL)
    {
      all->alias = new;
      return ;
    }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
}
