/*
** my_exit.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon May 16 13:50:02 2016 Lucas Villeneuve
** Last update Fri May 20 13:34:09 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

void	my_simple_exit(char **cmd, t_all *all)
{
  free_tab(cmd);
  free_tree(all->tree);
  free_env(all->env);
  free_path(all->path);
  free_cd(all->cd);
  exit(0);
}

void	my_advanced_exit(char **cmd, t_all *all, int ret)
{
  free_tab(cmd);
  free_tree(all->tree);
  free_env(all->env);
  free_path(all->path);
  free_cd(all->cd);
  exit(ret);
}
