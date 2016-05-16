/*
** my_free.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 17:30:02 2016 Lucas Villeneuve
** Last update Mon May 16 13:43:03 2016 Lucas Villeneuve
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

  i = 0;
  while (tree->next[i] != NULL)
    {
      free(tree->next[i++]);
    }
  free(tree->next);
  free(tree->cmd);
  free(tree);
}

void	free_env(t_env env)
{
  int	i;

  i = 0;
  while (env.tab[i] != NULL)
    free(env.tab[i++]);
  free(env.tab);
}

void	free_path(char **path)
{
  int	i;

  i = 0;
  while (path[i])
    free(path[i++]);
  free(path);
}
