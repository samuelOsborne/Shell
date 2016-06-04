/*
** command_not_found.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Jun  1 10:49:12 2016 Lucas Villeneuve
** Last update Sat Jun  4 14:54:11 2016 Lucas Villeneuve
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

int		is_dir(char *cmd)
{
  struct stat	buffer;

  if (stat(cmd, &buffer) != 0)
    return (0);
  return (S_ISDIR(buffer.st_mode));
}

char	**no_match(char **tab)
{
  my_put_err(tab[0]);
  my_put_err(": No match.\n");
  free_tab(tab);
  return (NULL);
}

char	*permission_denied(char *cmd)
{
  my_put_err(cmd);
  my_put_err(": Permission denied.\n");
  free(cmd);
  return (NULL);
}

char	*command_not_found(char *cmd)
{
  my_put_err(cmd);
  my_put_err(": Command not found.\n");
  free(cmd);
  return (NULL);
}
