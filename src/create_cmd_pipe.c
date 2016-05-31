/*
** create_cmd_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 25 14:43:29 2016 Lucas Villeneuve
** Last update Tue May 31 18:23:22 2016 Lucas Villeneuve
*/

#include <string.h>
#include <stdlib.h>
#include "42sh.h"

int	count_nb_case_pipe(char **tab)
{
  int	count;
  int	i;

  count = 1;
  i = 0;
  while (tab[i] != NULL)
    {
      if (strcmp(tab[i], "|") == 0 || strcmp(tab[i], ">") == 0 ||
	  strcmp(tab[i], ">>") == 0 || strcmp(tab[i], "<") == 0 ||
	  strcmp(tab[i], "<<") == 0)
	count += 2;
      i++;
    }
  return (count);
}

int	count_nb_args(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	fill_cmd_pipe_redir(char **tab, t_pipe *pipe, int args)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  pipe[i++].tab[0] = tab[k++];
  pipe[i++].tab[0] = tab[k++];
  while (k < args)
    {
      if (strcmp(tab[k], "|") == 0 || strcmp(tab[k], ">") == 0 ||
	  strcmp(tab[k], ">>") == 0 || strcmp(tab[k], "<") == 0 ||
	  strcmp(tab[k], "<<") == 0)
	{
	  if (k != 2)
	    ++i;
	  pipe[i++].tab[0] = tab[k++];
	  j = 0;
	}
      pipe[i].tab[j++] = tab[k++];
    }
}

void	fill_cmd_pipe(char **tab, t_pipe *pipe, int args)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  if (check_pipe(tab[0]) == 1)
    fill_cmd_pipe_redir(tab, pipe, args);
  else
    {
      while (k < args)
	{
	  if (strcmp(tab[k], "|") == 0 || strcmp(tab[k], ">") == 0 ||
	      strcmp(tab[k], ">>") == 0 || strcmp(tab[k], "<") == 0 ||
	      strcmp(tab[k], "<<") == 0)
	    {
	      pipe[i++].tab[j] = NULL;
	      pipe[i++].tab[0] = tab[k++];
	      j = 0;
	    }
	  pipe[i].tab[j++] = tab[k++];
	}
      pipe[i].tab[j] = NULL;
    }
}

t_pipe		*create_cmd_pipe(char **tab)
{
  t_pipe	*pipe;
  int		nb;
  int		args;
  int		i;

  nb = count_nb_case_pipe(tab);
  args = count_nb_args(tab);
  if (args < 3)
    {
      my_put_err("Error number parsing\n");
      return (NULL);
    }
  if ((pipe = calloc(nb + 1, sizeof(t_pipe))) == NULL)
    return (NULL);
  i = 0;
  while (i < nb)
    if ((pipe[i++].tab = calloc(args, sizeof(char *))) == NULL)
      return (NULL);
  pipe[nb].tab = NULL;
  fill_cmd_pipe(tab, pipe, args);
  return (pipe);
}
