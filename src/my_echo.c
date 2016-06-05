/*
** my_echo.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Tue May 17 10:39:21 2016 Lucas Villeneuve
** Last update Sun Jun  5 13:28:43 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	check_marks(char **str, int i, int j)
{
  int	d_mark;
  int	s_mark;

  d_mark = 0;
  s_mark = 0;
  while (str[++i] != NULL)
    {
      j = -1;
      while (str[i][++j] != 0)
	{
	  if (str[i][j] == 34 && s_mark % 2 == 0)
	    d_mark++;
	  if (str[i][j] == 39 && d_mark % 2 == 0)
	    s_mark++;
	}
    }
  if (d_mark % 2 == 1 || s_mark % 2 == 1)
    {
      if (d_mark % 2 == 1)
	my_put_err("Unmatched \".\n");
      else
	my_put_err("Unmatched \'.\n");
      return (1);
    }
 return (0);
}

void	write_special_char(char str, char *string)
{
  int	j;

  j = 0;
  while (string[j])
    {
      if (string[j] == str)
	{
	  my_putchar('\a' + j);
	  return ;
	}
      j++;
    }
  my_putchar('\\');
}

void	my_putstr_echo(char *str, int *d_mark, int *s_mark, t_all *all)
{
  int	i;
  char	string[7];

  strcpy(string, "abtnvfr");
  i = 0;
  while (str[i])
    {
      if (str[i] == 34 && *s_mark % 2 == 0)
	*d_mark += 1;
      else if (str[i] == 39 && *d_mark % 2 == 0)
	*s_mark += 1;
      else if (str[i] == '\\' || str[i] == '$')
	{
	  if (str[i] == '\\' && (*s_mark % 2 != 0 || *d_mark % 2 != 0))
	    write_special_char(str[++i], string);
	  else if (str[i] == '$')
	    i = write_dollar(str, i + 1, all);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

int	check_echo(char **cmd, t_all *all)
{
  if (check_dollar(cmd, -1, -1, all) == 1 || (check_marks(cmd, -1, -1) == 1))
    {
      all->status = 1;
      return (1);
    }
  return (0);
}

void	my_echo(char **cmd, t_all *all)
{
  int	i;
  int	arg;
  int	d_mark;
  int	s_mark;

  if (check_echo(cmd, all) == 1 )
    return ;
  arg = 0;
  i = 1;
  if (strcmp(cmd[i], "-n") == 0)
    {
      arg = 1;
      i++;
    }
  d_mark = 0;
  s_mark = 0;
  while (cmd[i] != NULL)
    {
      my_putstr_echo(cmd[i], &d_mark, &s_mark, all);
      if (cmd[i + 1] != NULL)
	my_putchar(' ');
      i++;
    }
  if (arg == 0)
    my_putchar('\n');
}
