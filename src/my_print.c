/*
** my_print.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 16:35:38 2016 Lucas Villeneuve
** Last update Wed May 11 16:41:23 2016 Lucas Villeneuve
*/

#include <unistd.h>

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return ;
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}
