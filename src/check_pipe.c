/*
** check_pipe.c for 42sh in /media/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Thu May 26 12:33:57 2016 Lucas Villeneuve
** Last update Thu May 26 12:35:37 2016 Lucas Villeneuve
*/

#include <string.h>

int	check_pipe(char *str)
{
  if (strcmp(str, "|") == 0 || strcmp(str, ">") == 0 ||
      strcmp(str, ">>") == 0 || strcmp(str, "<") == 0 ||
      strcmp(str, "<<") == 0)
    return (1);
  return (0);
}
