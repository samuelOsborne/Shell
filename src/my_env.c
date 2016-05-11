/*
** my_env.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 18:24:46 2016 Lucas Villeneuve
** Last update Wed May 11 18:28:48 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

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
