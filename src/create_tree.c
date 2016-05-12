/*
** create_tree.c for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 18:45:52 2016 escorn_t
** Last update Thu May 12 11:16:45 2016 escorn_t
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int		add_in_tree(t_tree *tree, char **tab, int i)
{
  t_tree	*new;
  t_tree       	*tmp;

  if ((new = malloc(sizeof(t_tree))) == NULL)
    return (-1);
  new->cmd = strdup(tab[i]);
  new->next = NULL;
  if (tree == NULL)
    tree = new;
  else
    {
      tmp = tree;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (0);
}

int		create_tree(t_tree *tree, char **tab)
{
  int		i;

  i = 0;
  tree = NULL;
  while (tab[i])
    {
      if (add_in_tree(tree, tab, i) == -1)
	return (-1);
      i++;
    }
  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
  return (0);
}
