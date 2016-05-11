/*
** main.c for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
** 
** Made by Lucas Villeneuve
** Login   <villen_l@epitech.net>
** 
** Started on  Wed May 11 15:59:33 2016 Lucas Villeneuve
** Last update Wed May 11 16:48:31 2016 Lucas Villeneuve
*/

#include <stdlib.h>
#include "42sh.h"

void	main_loop()
{
  char	*line;

  while (42)
    {
      my_putstr("-->");
      line = get_next_line(0);
      my_str_to_wordtab(line, ' ');
      free(line);
    }
}

int	main()
{
  main_loop();
  return (0);
}
