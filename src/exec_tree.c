/*
** exec_tree.c for 42s in /home/escorn_t/Rendu/TMP_SHELL
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 25 15:53:57 2016 escorn_t
** Last update Sat Jun  4 14:52:42 2016 Lucas Villeneuve
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int		launch_exec(t_tree *tree, t_all *all)
{
  char		**tab;

  tree->cmd = merge_alias(all, tree->cmd);
  tree->cmd = epurstr(tree->cmd);
  tab = my_str_to_wordpipe(tree->cmd);
  tab = find_type_cmd(tab, all);
  if (tab != NULL)
    free_tab(tab);
  return (0);
}

int		get_nb_separators(char *s)
{
  int		i;
  int		compt;

  i = 0;
  compt = 0;
  while (s[i])
    {
      if ((s[i] == '|' && s[i + 1] == '|') || (s[i] == '&' && s[i + 1] == '&'))
	{
	  compt++;
	  i += 2;
	}
      i++;
    }
  return (compt);
}

char		*get_last_cmd(char *s, int pos)
{
  int		cmpt;
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  cmpt = 0;
  if ((res = malloc(strlen(s) + 1)) == NULL)
    error_malloc();
  while (cmpt < pos)
    {
      while (s[i] && ((s[i] != '|' && s[i] != '&') || s[i + 1] != s[i]))
	i++;
      if (s[i])
	i = i + 2;
      cmpt++;
    }
  while (s[i] && ((s[i] != '|' && s[i] != '&') || s[i + 1] != s[i]))
    res[j++] = s[i++];
  res[j] = 0;
  return (epurstr(res));
}

t_tree		*new_tree_next(char *cmd, int pos)
{
  t_tree	*new;

  if ((new = malloc(sizeof(t_tree))) == NULL)
    error_malloc();
  new->cmd = get_last_cmd(cmd, pos);
  new->next = NULL;
  return (new);
}

int		create_exec_tree(t_tree *tree)
{
  int		i;
  int		cmpt_sep;

  cmpt_sep = get_nb_separators(tree->cmd);
  i = 0;
  if ((tree->next = malloc((cmpt_sep + 2) * sizeof(t_tree *))) == NULL)
    error_malloc();
  while (i < cmpt_sep + 1)
    {
      tree->next[i] = new_tree_next(tree->cmd, i);
      i++;
    }
  tree->next[i] = NULL;
  get_spec(tree, cmpt_sep);
  return (0);
}
