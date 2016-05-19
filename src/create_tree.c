/*
** create_tree.c for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 18:45:52 2016 escorn_t
** Last update Thu May 19 10:27:19 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char		*get_word(char *s, char c, int pos)
{
  char		*res;
  int		i;
  int		j;
  int		compt;

  i = 0;
  j = 0;
  compt = 0;
  if ((res = calloc(strlen(s) + 1, sizeof(char))) == NULL)
    error_malloc();
  while (compt < pos)
    {
      while (s[i] && s[i] != c)
	i++;
      i++;
      compt++;
    }
  while (s[i] && s[i] != c)
    res[j++] = s[i++];
  res[j] = 0;
  return (res);
}

t_tree		*add_in_tree_tab(t_tree *tree, int i)
{
  t_tree	*new;

  if ((new = calloc(1, sizeof(t_tree))) == NULL)
    error_malloc();
  if (tree->cmd == NULL)
    new->cmd = NULL;
  else
    new->cmd = get_word(tree->cmd, ';', i);
  new->next = NULL;
  return (new);
}

int		get_nb_word(char *s, char c)
{
  int		i;
  int		compt;

  compt = 1;
  i = 0;
  while (s && s[i])
    {
      if (s[i] == c)
	compt++;
      i++;
    }
  return (compt);
}

int		create_tree(t_tree *tree)
{
  int		i;

  if (tree == NULL)
    return (1);
  tree->next = calloc(get_nb_word(tree->cmd, ';') + 1, sizeof(t_tree *));
  if (tree->next == NULL)
    error_malloc();
  i = 0;
  while (i < get_nb_word(tree->cmd, ';'))
    {
      if ((tree->next[i] = add_in_tree_tab(tree, i)) == NULL)
	return (-1);
      i++;
    }
  tree->next[i] = NULL;
  return (0);
}
