/*
** my_cd.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Fri May 20 12:51:22 2016 Lucas Villeneuve
** Last update Tue May 31 11:09:05 2016 Lucas Villeneuve
*/

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

void	my_cd_dash(t_cd *cd)
{
  if (cd->old == NULL || cd->pwd == NULL)
    {
      my_put_err("Error directory\n");
      return ;
    }
  if (chdir(cd->old) == -1)
    my_put_err("Wrong directory\n");
  else
    {
      my_putstr(cd->old);
      my_putchar('\n');
      swap_cd(cd);
    }
}

void	my_simple_cd(t_cd *cd, char **cmd)
{
  if (cd->old == NULL || cd->pwd == NULL)
    {
      my_put_err("Error directory\n");
      return ;
    }
  if (chdir(cmd[1]) == -1)
    my_put_err("Wrong directory\n");
  else
    {
      update_cd(cd, strlen(cd->pwd) + strlen(cmd[1]) + 2);
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
	my_put_err("Error home directory\n");
      else
	{
	  if (all->cd.pwd == NULL)
	    {
	      my_put_err("Can't update PWD\n");
	      return ;
	    }
	  update_cd(&all->cd, strlen(tmp) + 1);
	  strcpy(all->cd.pwd, tmp);
	  free(tmp);
	}
    }
  else if (strcmp(cmd[1], "-") == 0)
    my_cd_dash(&all->cd);
  else
    my_simple_cd(&all->cd, cmd);
}
