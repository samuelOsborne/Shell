/*
** get_next_line.c for mysh2 in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/SHELL/PSU_2015_minishell2
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Mar 28 15:07:18 2016 Lucas Villeneuve
** Last update Wed May 11 17:20:57 2016 Lucas Villeneuve
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		read_char(const int fd)
{
  static char	*tmp;
  static char	buffer[READ_SIZE];
  static int	ret = 0;
  char		c;

  if (ret == 0)
    {
      if ((ret = read(fd, buffer, READ_SIZE)) <= 0)
	return (0);
      tmp = buffer;
    }
  c = *tmp;
  tmp++;
  ret--;
  return (c);
}

char		*get_next_line(const int fd)
{
  char		c;
  char		*str;
  int		i;
  int		j;

  if ((str = calloc(READ_SIZE + 1, sizeof(char))) == NULL || fd == -1)
    return (NULL);
  j = 2;
  i = 0;
  c = read_char(fd);
  while (c != '\n' && c != 0)
    {
      str[i++] = c;
      c = read_char(fd);
      if (i == (READ_SIZE * (j - 1)))
      	{
      	  str = realloc(str, READ_SIZE * j);
      	  j++;
      	}
    }
  str[i] = 0;
  if (str[0] == 0 && c == 0)
    return (NULL);
  return (str);
}
