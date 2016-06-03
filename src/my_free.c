/*
** my_free.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 17:30:02 2016 Lucas Villeneuve
** Last update Thu Jun  2 14:36:09 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

void	free_tab(char **tab)
{
  int	i;

  if (tab == NULL)
    return ;
  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

void	free_tree(t_tree *tree)
{
  int	i;
  int	j;

  i = 0;
  while (tree->next[i] != NULL)
    {
      j = 0;
      while (tree->next[i]->next[j] != NULL)
	free(tree->next[i]->next[j++]);
      free(tree->next[i++]);
    }
  free(tree->next);
  free(tree->cmd);
  free(tree);
}

void	free_env(t_env env)
{
  int	i;

  if (!env.tab)
    return ;
  i = 0;
  while (env.tab[i] != NULL)
    free(env.tab[i++]);
  free(env.tab);
}

void	free_path(char **path)
{
  int	i;

  if (!path)
    return ;
  i = 0;
  while (path[i] != NULL)
    free(path[i++]);
  free(path);
}

void	free_cd(t_cd cd)
{
  if (cd.old != NULL)
    free(cd.old);
  if (cd.pwd != NULL)
    free(cd.pwd);
}
