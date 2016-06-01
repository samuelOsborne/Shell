/*
** get_spec.c for 42sh in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Mon May 30 15:28:28 2016 escorn_t
** Last update Wed Jun  1 15:43:18 2016 escorn_t
*/

#include <stdlib.h>
#include "42sh.h"

int		launch_condition(t_all *all, char *spec, int pos)
{
  if (pos == 0)
    return (0);
  if (spec[pos - 1] == '|')
    {
      if (all->status == 0)
	return (-1);
      else
	return (0);
    }
  if (spec[pos - 1] == '&')
    {
      if (all->status != 0)
	return (-1);
      else
	return (0);
    }
  return (0);
}

char		get_i_spec(char *s, int pos)
{
  int		cmpt;
  int		i;

  i = 0;
  cmpt = 0;
  while (cmpt < pos)
    {
      while (s[i] && (s[i] != '|' || s[i] != '&') && s[i] != s[i + 1])
	i++;
      if (s[i] && s[i + 1])
	i = i + 2;
      cmpt++;
    }
  while (s[i] && (s[i] != '|' || s[i] != '&') && s[i] != s[i + 1])
    i++;
  return (s[i]);
}

void		get_spec(t_tree *tree, int cmpt)
{
  int		i;

  i = 0;
  if ((tree->spec = malloc(cmpt + 2)) == NULL)
    error_malloc();
  if (cmpt == 0)
    {
      tree->spec[0] = 0;
      return ;
    }
  while (i < cmpt)
    {
      tree->spec[i] = get_i_spec(tree->cmd, i);
      i++;
    }
  tree->spec[i] = 0;
}
