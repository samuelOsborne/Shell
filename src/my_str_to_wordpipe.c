/*
** my_str_to_wordpipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon May 23 10:24:30 2016 Lucas Villeneuve
** Last update Thu May 26 12:45:29 2016 Lucas Villeneuve
*/
#include <stdlib.h>
#include <string.h>
#include "42sh.h"

void	put_pipe(char **tab, char *str, int *i, int *j)
{
  if (str[*i] == '|' || str[*i] == ' ' || str[*i] == '>' || str[*i] == '<')
    {
      if (str[*i] == '|' || str[*i] == '>' || str[*i] == '<')
	{
	  if (*i > 0 && str[*i - 1] != ' ')
	    *j += 1;
	  if (str[*i + 1] == '>' || str[*i + 1] == '<')
	    {
	      tab[*j][0] = str[*i];
	      tab[*j][1] = str[*i + 1];
	      tab[*j][2] = 0;
	      *i += 1;
	    }
	  else
	    {
	      tab[*j][0] = str[*i];
	      tab[*j][1] = 0;
	    }
	  if (str[*i + 1] != ' ')
	    *j += 1;
	}
      else
	*j += 1;
      *i += 1;
    }
}

char	**put_in_wordpipe(char **tab, char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      k = 0;
      while (str[i] != '|' && str[i] != '>' && str[i] != '<'
	     && str[i] != ' ' && str[i] != 0)
	tab[j][k++] = str[i++];
      if (tab[j][0] != '|' && tab[j][0] != '<' && tab[j][0] != '>')
	tab[j][k] = 0;
      put_pipe(tab, str, &i, &j);
    }
  return (tab);
}

int	parse_error_pipe(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '|' || str[i] == '<' || str[i] == '>')
	{
	  if (str[i] == '|' && (str[i + 1] == '>' || str[i + 1] == '<'))
	    return (error_pipe(str[i + 1]));
	  else if (str[i] == '>' && (str[i + 1] == '<' || str[i + 1] == '|'))
	    return (error_pipe(str[i + 1]));
	  else if (str[i] == '<' && (str[i + 1] == '>' || str[i + 1] == '|'))
	    return (error_pipe(str[i + 1]));
	}
      i++;
    }
  return (0);
}

char	**my_str_to_wordpipe(char *str)
{
  int	i;
  int	len;
  int	nb_args;
  char	**tab;

  if (str == NULL || parse_error_pipe(str) == 2)
    return (NULL);
  nb_args = count_args_wordpipe(str);
  len = strlen(str);
  if ((tab = calloc(nb_args + 1, sizeof(char *))) == NULL)
    error_malloc();
  i = 0;
  while (i < nb_args)
    if ((tab[i++] = calloc(len + 1, sizeof(char))) == NULL)
      error_malloc();
  tab = put_in_wordpipe(tab, str);
  tab[nb_args] = NULL;
  free(str);
  return (tab);
}
