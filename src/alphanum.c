/*
** alphanum.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Sun Jun  5 11:13:16 2016 Lucas Villeneuve
** Last update Sun Jun  5 15:05:46 2016 Samuel
*/

#include "42sh.h"

int	alphanum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9')
	  && (str[i] < 'A' || str[i] > 'Z')
	  && (str[i] < 'a' || str[i] > 'z'))
	{
	  my_put_err("setenv: ");
	  my_put_err("Variable name must contain alphanumeric characters.\n");
	  return (1);
	}
      i++;
    }
  return (0);
}
