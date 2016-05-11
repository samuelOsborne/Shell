/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Wed May 11 16:47:38 2016 Lucas Villeneuve
*/

#ifndef _42SH_H_
# define _42SH_H_

void	my_putchar(char c);
void	my_putstr(char *str);
char	*get_next_line(int fd);
char	**my_str_to_wordtab(char *str, char opt);

#endif /* !_42SH_H_ */
