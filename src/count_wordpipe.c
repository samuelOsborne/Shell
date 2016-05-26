/*
** count_parse_wordpipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu May 26 12:44:03 2016 Lucas Villeneuve
** Last update Thu May 26 12:45:28 2016 Lucas Villeneuve
*/

#include "42sh.h"

void	count_pipe(char *str, int *i, int *count)
{
  if (str[*i + 1] == '|' || str[*i + 1] == '>' || str[*i + 1] == '<')
    {
      if (str[*i + 2] == ' ' || str[*i + 2] == '>' || str[*i + 2] == '<')
	{
	  if ((str[*i + 2] == '>' || str[*i + 2] == '<') && str[*i + 3] == ' ')
	    *i += 1;
	  *i += 1;
	}
      *i += 1;
      *count += 1;
    }
  *count += 1;
}

int	count_args_wordpipe(char *str)
{
  int	i;
  int	count;

  count = 1;
  if (str[0] == '|' || str[0] == '>' || str[0] == '<')
    count = 0;
  i = -1;
  while (str[++i] != 0)
    {
      if (str[i] == ' ' && str[i + 1] != 0)
	count_pipe(str, &i, &count);
      else if ((str[i] == '|' || str[i] == '>' || str[i] == '<')
	       && str[i + 1] != 0)
	{
	  if (str[i + 1] != ' ')
	    {
	      if ((str[i + 1] == '>' || str[i + 1] == '<') && str[i + 2] == ' ')
		i++;
	      i++;
	      count++;
	    }
	  count++;
	}
    }
  return (count);
}
