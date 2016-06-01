/*
** command_not_found.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed Jun  1 10:49:12 2016 Lucas Villeneuve
** Last update Wed Jun  1 10:55:04 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

char	*command_not_found(char *cmd)
{
  my_put_err(cmd);
  my_put_err(": Command not found.\n");
  free(cmd);
  return (NULL);
}
