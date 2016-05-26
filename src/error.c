/*
** error.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 17:00:47 2016 Lucas Villeneuve
** Last update Tue May 24 11:52:06 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

void	error_malloc()
{
  my_put_err("Error malloc\n");
  exit(1);
}

int	error_pipe(char c)
{
  my_put_err("Error parsing near ");
  my_putchar_err(c);
  my_putchar_err('\n');
  return (2);
}
