/*
** globbing.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sat Jun  4 11:06:53 2016 Lucas Villeneuve
** Last update Sat Jun  4 14:54:27 2016 Lucas Villeneuve
*/

#include <glob.h>
#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	check_for_star(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '*' || str[i] == '~')
	return (1);
      i++;
    }
  return (0);
}

void		fill_tab_with_glob(int *i, int *j, glob_t buf, char **cmd)
{
  unsigned int	tmp;

  *j += 1;
  tmp = 0;
  while (tmp < buf.gl_pathc)
    {
      cmd[*i] = strdup(buf.gl_pathv[tmp++]);
      *i += 1;
    }
}

char		**my_glob(char *path, char **tab, int pos)
{
  char		**cmd;
  glob_t	buf;
  int		len;
  int		i;
  int		j;

  buf.gl_offs = 0;
  if (glob(path, GLOB_TILDE | GLOB_TILDE_CHECK, NULL, &buf) == GLOB_NOMATCH)
    return (no_match(tab));
  len = count_nb_args(tab) + buf.gl_pathc - 1;
  if ((cmd = calloc(len + 1, sizeof(char *))) == NULL)
    error_malloc();
  i = 0;
  j = 0;
  while (i < len)
    {
      if (i == pos)
	fill_tab_with_glob(&i, &j, buf, cmd);
      else
	cmd[i++] = strdup(tab[j++]);
    }
  cmd[i] = NULL;
  free_tab(tab);
  globfree(&buf);
  return (cmd);
}
