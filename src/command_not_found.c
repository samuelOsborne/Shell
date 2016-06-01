/*
** command_not_found.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Jun  1 10:49:12 2016 Lucas Villeneuve
** Last update Wed Jun  1 12:58:03 2016 Lucas Villeneuve
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "42sh.h"

char 		*got_right(char *cmd)
{
  struct stat	buffer;

  if (stat(cmd, &buffer) != 0)
    return (0);
  if (buffer.st_mode & S_IWOTH)
    return (cmd);
  my_put_err(cmd);
  my_put_err(": Permission denied.\n");
  free(cmd);
  return (NULL);
}

int		is_dir(char *cmd)
{
  struct stat	buffer;

  if (stat(cmd, &buffer) != 0)
    return (0);
  return (S_ISDIR(buffer.st_mode));
}

char	*command_not_found(char *cmd)
{
  my_put_err(cmd);
  my_put_err(": Command not found.\n");
  free(cmd);
  return (NULL);
}
