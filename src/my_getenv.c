/*
** my_getenv.c<2> for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 13 13:28:34 2016 Lucas Villeneuve
** Last update Mon May 16 14:46:48 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	my_getenv_line(char **env, char *str)
{
  int	i;
  char	*tmp;

  i = 0;
  if ((tmp = calloc(strlen(str) + 2, sizeof(char))) == NULL)
    error_malloc();
  strcpy(tmp, str);
  strcat(tmp, "=");
  while (env[i])
    {
      if (strncmp(env[i], tmp, strlen(tmp)) == 0)
	{
	  free(tmp);
	  return (i);
	}
      i++;
    }
  free(tmp);
  return (-1);
}

char	*my_getenv(char **env, char *str)
{
  int	i;
  int	j;
  int	k;
  char	*tmp;

  i = 0;
  k = 0;
  while (env[i])
    {
      j = 0;
      while (env[i][j] == str[j] && str[j])
	j++;
      if (!str[j])
	{
	  if ((tmp = calloc(strlen(env[i]), sizeof(char))) == NULL)
	    error_malloc();
	  while (env[i][j])
	    tmp[k++] = env[i][j++];
	  tmp[k] = 0;
	  return (tmp);
	}
      i++;
    }
  return (NULL);
}
