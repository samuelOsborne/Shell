/*
** epurstr.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 17:35:19 2016 Lucas Villeneuve
** Last update Thu May 19 10:30:06 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

char	*loop_epurstr(char *str, char *tmp, int i, int j)
{
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	tmp[j++] = str[i++];
      else
	{
	  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	    i++;
	  if (str[i])
	    tmp[j++] = ' ';
	  else
	    {
	      tmp[j] = 0;
	      return (tmp);
	    }
	}
    }
  tmp[j] = 0;
  return (tmp);
}

char	*epurstr(char *str)
{
  char	*tmp;
  int	i;

  if (str == NULL)
    return (NULL);
  if ((tmp = calloc(strlen(str) + 1, sizeof(char))) == NULL)
    error_malloc();
  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  tmp = loop_epurstr(str, tmp, i, 0);
  free(str);
  return (tmp);
}
