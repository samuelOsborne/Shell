/*
** my_str_to_wordtab.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 16:45:47 2016 Lucas Villeneuve
** Last update Wed May 11 18:10:00 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include <string.h>
#include "42sh.h"

char	**put_in_wordtab(char **tab, char *str, char opt)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      k = 0;
      while (str[i] != opt && str[i] != 0)
	{
	  tab[j][k] = str[i];
	  i++;
	  k++;
	}
      tab[j][k] = 0;
      if (str[i] == opt)
	{
	  j++;
	  i++;
	}
    }
  return (tab);
}

int	count_args_wordtab(char *str, char opt)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (str[i] != 0)
    {
      if (str[i] == opt && str[i + 1] != 0)
	count++;
      i++;
    }
  return (count);
}

char	**my_str_to_wordtab(char *str, char opt)
{
  int	i;
  int	len;
  int	nb_args;
  char	**tab;

  if (str == NULL)
    return (NULL);
  nb_args = count_args_wordtab(str, opt);
  len = strlen(str);
  if ((tab = calloc(nb_args + 1, sizeof(char *))) == NULL)
    error_malloc();
  i = 0;
  while (i < nb_args)
    if ((tab[i++] = calloc(len + 1, sizeof(char)) ) == NULL)
      error_malloc();
  tab = put_in_wordtab(tab, str, opt);
  tab[nb_args] = NULL;
  free(str);
  return (tab);
}
