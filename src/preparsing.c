/*
** preparsing.c for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Sun Jun  5 12:18:39 2016 escorn_t
** Last update Sun Jun  5 14:30:25 2016 escorn_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

int		test_error(char *s, int p)
{
  char		*tab;
  int		i;

  tab = "|&<>;";
  if (s[p] != ';' && !s[p + 1])
    {
      fprintf(stderr, "Parsing error near %c\n", s[p]);
      return (-1);
    }
  i = 0;
  while (tab[i])
    {
      if (tab[i] == s[p + 1] && s[p] != s[p + 1])
	{
	  fprintf(stderr, "Parsing error near %c%c\n", s[p], s[p + 1]);
	  return (-1);
	}
      if (tab[i] == s[p + 2])
	{
	  fprintf(stderr, "Parsing error near %c%c%c\n", s[p], s[p + 1], s[p + 2]);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int		parse_for_errors(char *s)
{
  int		i;
  int		j;
  char		*tab;

  i = 0;
  tab = "|&><;";
  if (!s || !s[0])
    return (-1);
  while (s[i])
    {
      j = 0;
      while (tab[j])
	{
	  if (tab[j] == s[i])
	    if (test_error(s, i) == -1)
	      return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}
