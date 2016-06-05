/*
** my_env.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 18:24:46 2016 Lucas Villeneuve
** Last update Sun Jun  5 12:51:01 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

void	print_env(t_env *env)
{
  int	i;

  i = 0;
  while (env->tab[i])
    {
      my_putstr(env->tab[i]);
      my_putchar('\n');
      i++;
    }
}

void	my_setenv_reset(char **cmd, t_env *env, int i, int len)
{
  free(env->tab[i]);
  if ((env->tab[i] = calloc(len + 2, sizeof(char))) == NULL)
    error_malloc();
  strcpy(env->tab[i], cmd[1]);
  strcat(env->tab[i], "=");
}

void	my_setenv(char **cmd, t_env *env, t_all *all)
{
  int	i;

  if (cmd[1] != NULL)
    {
      if (alphanum(cmd[1]) == 1)
	{
	  all->status = 1;
	  return ;
	}
      i = my_getenv_line(env->tab, cmd[1]);
      if (i != -1 && cmd[2] != NULL)
	{
	  my_setenv_reset(cmd, env, i, strlen(cmd[1]) + strlen(cmd[2]));
	  strcat(env->tab[i], cmd[2]);
	}
      else if (i != -1)
	my_setenv_reset(cmd, env, i, strlen(cmd[1]));
      else if (i == -1)
	{
	  env->size++;
	  env->tab = recreate_tab_set(cmd, env->tab, env->size);
	}
    }
  else
    print_env(env);
}

void	my_unsetenv(char **cmd, t_env *env, t_all *all)
{
  int	i;
  int	j;

  if (cmd[1] != NULL)
    {
      j = 1;
      while (cmd[j])
	{
	  i = my_getenv_line(env->tab, cmd[j]);
	  if (i != -1)
	    {
	      env->size--;
	      env->tab = recreate_tab_unset(env->tab, env->size, i);
	    }
	  j++;
	}
    }
  else
    {
      my_put_err("unsetenv: Too few arguments.\n");
      all->status = 1;
    }
}

char	**create_env(char **ae, int i)
{
  int	j;
  char	**env;

  if ((env = calloc(i + 1, sizeof(char *))) == NULL)
    error_malloc();
  j = 0;
  while (j < i)
    {
      if ((env[j] = calloc(strlen(ae[j]) + 1, sizeof(char))) == NULL)
	error_malloc();
      strcpy(env[j], ae[j]);
      j++;
    }
  env[j] = NULL;
  return (env);
}
