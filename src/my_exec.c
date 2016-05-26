/*
** my_exec.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu May 12 16:51:55 2016 Lucas Villeneuve
** Last update Wed May 25 17:13:06 2016 Lucas Villeneuve
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "42sh.h"

char 	*create_path(char *path, char *cmd)
{
  char	*tmp;

  if ((tmp = calloc(strlen(cmd) + strlen(path) + 2, sizeof(char))) == NULL)
    error_malloc();
  strcpy(tmp, path);
  strcat(tmp, "/");
  strcat(tmp, cmd);
  return (tmp);
}

char	*find_bin_without_path(char **cmd)
{
  if (cmd[0][0] == '.' || cmd[0][0] == '/')
    {
      if (access(cmd[0], F_OK | X_OK) == 0)
	return (cmd[0]);
      else
	{
	  my_put_err("Command not found\n");
	  free(cmd[0]);
	  return (NULL);
	}
    }
  my_put_err("Command not found\n");
  free(cmd[0]);
  return (NULL);
}

char	*check_relative_path(char **cmd)
{
  if (access(cmd[0], F_OK | X_OK) == 0)
    return (cmd[0]);
  else
    {
      my_put_err("Command not found\n");
      free(cmd[0]);
      return (NULL);
    }
}

char	*find_bin(char **path, char **cmd)
{
  char	*tmp;
  int	ret;
  int	i;

  if (cmd[0][0] == '.' || cmd[0][0] == '/')
    return (check_relative_path(cmd));
  ret = -1;
  i = 0;
  while (ret == -1 && path[i])
    {
      tmp = create_path(path[i++], cmd[0]);
      if ((ret = access(tmp, F_OK | X_OK)) == 0)
	{
	  free(cmd[0]);
	  return (tmp);
	}
      free(tmp);
    }
  my_put_err("Command not found\n");
  free(cmd[0]);
  return (NULL);
}

void	my_simple_exec(char **cmd, char **path, t_env *env)
{
  int	status;
  int	pid;

  if (path != NULL)
    cmd[0] = find_bin(path, cmd);
  else
    cmd[0] = find_bin_without_path(cmd);
  if (cmd[0] != NULL)
    {
      if ((pid = fork()) == -1)
	return ;
      else if (pid == 0)
	{
	  execve(cmd[0], cmd, env->tab);
	  exit(0);
	}
      else
	{
	  wait(&status);
	  if (status == 11 || status == 139 || status == SIGSEGV)
	    my_put_err("Segmentation fault\n");
	}
    }
}
