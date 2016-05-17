/*
** manage_tab_env.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon May 16 14:22:07 2016 Lucas Villeneuve
** Last update Mon May 16 14:48:11 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	put_env_line_arg(char **cmd, char **env, int j)
{
  if ((env[j] = calloc(strlen(cmd[1]) + strlen(cmd[2]) + 2,
		       sizeof(char))) == NULL)
    error_malloc();
  strcpy(env[j], cmd[1]);
  strcat(env[j], "=");
  strcat(env[j++], cmd[2]);
  return (j);
}

char	**recreate_tab_set(char **cmd, char **ae, int i)
{
  char	**env;
  int	j;

  if ((env = calloc(i + 1, sizeof(char *))) == NULL)
    error_malloc();
  j = 0;
  while (j < i - 1)
    {
      if ((env[j] = calloc(strlen(ae[j]) + 1, sizeof(char))) == NULL)
	error_malloc();
      strcpy(env[j], ae[j]);
      free(ae[j++]);
    }
  if (cmd[2] != NULL)
    j = put_env_line_arg(cmd, env, j);
  else
    {
      if ((env[j] = calloc(strlen(cmd[1]) + 2, sizeof(char))) == NULL)
	error_malloc();
      strcpy(env[j], cmd[1]);
      strcat(env[j++], "=");
    }
  free(ae);
  env[j] = NULL;
  return (env);
}

char	**recreate_tab_unset(char **ae, int i, int del)
{
  char	**env;
  int	j;
  int	k;

  if ((env = calloc(i + 1, sizeof(char *))) == NULL)
    error_malloc();
  j = 0;
  k = 0;
  while (j < i)
    {
      if (j == del)
	free(ae[k++]);
      if ((env[j] = calloc(strlen(ae[k]) + 1, sizeof(char))) == NULL)
	error_malloc();
      strcpy(env[j], ae[k]);
      free(ae[k++]);
      j++;
    }
  if (j == del)
    free(ae[k++]);
  free(ae);
  env[j] = NULL;
  return (env);
}
