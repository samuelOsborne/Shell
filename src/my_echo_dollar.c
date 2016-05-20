/*
** my_echo_dollar.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 18 19:15:10 2016 Lucas Villeneuve
** Last update Fri May 20 15:07:53 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char	*create_tmp(char **str, int i, int *j)
{
  char	*tmp;
  int	k;

  if ((tmp = calloc(strlen(str[i]) + 1, sizeof(char))) == NULL)
    error_malloc();
  k = 0;
  *j += 1;
  while (str[i][*j] && str[i][*j] != ' ' &&
	 str[i][*j] != '\"' && str[i][*j] != '\'')
    {
      if (str[i][*j] != ' ' &&
	  (str[i][*j] < 48 || (str[i][*j] > 57 && str[i][*j] < 65)
	   || (str[i][*j] > 90 && str[i][*j] < 97) || str[i][*j] > 122))
	{
	  my_put_err("Illegal variable name.\n");
	  free(tmp);
	  return (NULL);
	}
      else
	tmp[k++] = str[i][*j];
      *j += 1;
    }
  tmp[k++] = '=';
  tmp[k] = 0;
  return (tmp);
}

int	check_dollar(char **str, int i, int j, t_all *all)
{
  char	*tmp;
  char	*var;

  while (str[++i] != NULL)
    {
      j = -1;
      while (str[i][++j] != 0)
	{
	  if (str[i][j] == '$')
	    {
	      if ((tmp = create_tmp(str, i, &j)) == NULL)
		return (1);
	      var = my_getenv(all->env.tab, tmp);
	      free(tmp);
	      if (var == NULL)
		{
		  my_put_err("Undefined variable.\n");
		  return (1);
		}
	      else
		free(var);
	    }
	}
    }
  return (0);
}
