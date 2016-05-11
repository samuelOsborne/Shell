/*
** get_next_line.c for mysh2 in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/SHELL/PSU_2015_minishell2
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Mon Mar 28 15:07:18 2016 Lucas Villeneuve
** Last update Mon Mar 28 15:07:23 2016 Lucas Villeneuve
*/

#include <unistd.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

void	my_memset(char *str, int size)
{
  char	*tmp;

  tmp = str;
  while (size > 0)
    {
      *tmp = 0;
      tmp++;
      size--;
    }
}

char	*my_realloc(char *str, size_t size)
{
  char	*newstr;
  int	i;

  newstr = malloc(size + my_strlen(str));
  if (newstr == NULL)
    return (NULL);
  my_memset(newstr, size + my_strlen(str));
  i = 0;
  while (str[i] != 0)
    {
      newstr[i] = str[i];
      i++;
    }
  newstr[i] = 0;
  free(str);
  return (newstr);
}

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

  if ((str = malloc(READ_SIZE + 1)) == NULL || fd == -1)
    return (NULL);
  my_memset(str, READ_SIZE + 1);
  j = 2;
  i = 0;
  c = read_char(fd);
  while (c != '\n' && c != 0)
    {
      str[i++] = c;
      c = read_char(fd);
      if (i == (READ_SIZE * (j - 1)))
      	{
      	  str = my_realloc(str, READ_SIZE * j);
      	  j++;
      	}
    }
  str[i] = 0;
  if (str[0] == 0 && c == 0)
    return (NULL);
  return (str);
}
