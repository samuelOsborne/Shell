/*
** my_cd.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 20 12:51:22 2016 Lucas Villeneuve
** Last update Sun Jun  5 13:02:52 2016 Lucas Villeneuve
*/

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42sh.h"

void	update_cd(t_cd *cd, int len)
{
  free(cd->old);
  if ((cd->old = calloc(strlen(cd->pwd) + 1, sizeof(char))) == NULL)
    error_malloc();
  strcpy(cd->old, cd->pwd);
  free(cd->pwd);
  if ((cd->pwd = calloc(len, sizeof(char))) == NULL)
    error_malloc();
}

void	swap_cd(t_cd *cd)
{
  char	*tmp;
  char	*tmp2;

  if ((tmp = calloc(strlen(cd->old) + 1, sizeof(char))) == NULL)
    error_malloc();
  if ((tmp2 = calloc(strlen(cd->pwd) + 1, sizeof(char))) == NULL)
    error_malloc();
  strcpy(tmp, cd->old);
  strcpy(tmp2, cd->pwd);
  free(cd->old);
  free(cd->pwd);
  if ((cd->old = calloc(strlen(tmp2) + 1, sizeof(char))) == NULL)
    error_malloc();
  if ((cd->pwd = calloc(strlen(tmp) + 1, sizeof(char))) == NULL)
    error_malloc();
  strcpy(cd->old, tmp2);
  strcpy(cd->pwd, tmp);
  free(tmp);
  free(tmp2);
}

void	my_cd_dash(t_cd *cd, t_all *all)
{
  if (cd->old == NULL || cd->pwd == NULL)
    {
      my_put_err(": No such file or directory.\n");
      all->status = 1;
      return ;
    }
  if (chdir(cd->old) == -1)
    {
      my_put_err(cd->old);
      my_put_err(": No such file or directory.\n");
      all->status = 1;
    }
  else
    swap_cd(cd);
}

void	my_simple_cd(t_cd *cd, char **cmd, t_all *all)
{
  if (chdir(cmd[1]) == -1)
    {
      my_put_err(cmd[1]);
      if (errno == ENOENT)
	my_put_err(": No such file or directory.\n");
      else if (errno == EACCES)
	my_put_err(": Permission denied.\n");
      else if (errno == ENOTDIR)
	my_put_err(": Not a directory.\n");
      all->status = 1;
    }
  else
    {
      if (cd->pwd != NULL)
	update_cd(cd, strlen(cd->pwd) + strlen(cmd[1]) + 2);
      if (cd->old != NULL)
	getcwd(cd->pwd, strlen(cd->old) + strlen(cmd[1]) + 2);
    }
}

void	my_cd(t_all *all, char **cmd)
{
  char	*tmp;

  if (cmd[1] == NULL || strcmp(cmd[1], "~") == 0)
    {
      tmp = my_getenv(all->env.tab, "HOME=");
      if (chdir(tmp) == -1)
	{
	  my_put_err("No $home variable set.\n");
	  all->status = 1;
	}
      else
	{
	  if (all->cd.pwd == NULL)
	    return ;
	  update_cd(&all->cd, strlen(tmp) + 1);
	  strcpy(all->cd.pwd, tmp);
	  free(tmp);
	}
    }
  else if (strcmp(cmd[1], "-") == 0)
    my_cd_dash(&all->cd, all);
  else
    my_simple_cd(&all->cd, cmd, all);
}
