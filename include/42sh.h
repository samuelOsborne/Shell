/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Fri May 13 17:39:37 2016 Lucas Villeneuve
*/

#ifndef _42SH_H_
# define _42SH_H_

typedef struct  s_tree
{
  char		*cmd;
  struct s_tree	**next;
}		t_tree;

typedef	struct	s_env
{
  int		size;
  char		**tab;
}		t_env;

typedef struct	s_all
{
  t_env		env;
  char		**path;
}		t_all;

void	error_malloc();
void	my_putchar(char c);
void	free_tab(char **tab);
void	my_putstr(char *str);
void	my_put_err(char *str);
void	my_putchar_err(char c);
void	free_tree(t_tree *tree);
void	find_type_cmd(char **tab, t_all *all);
void	my_simple_exec(char **cmd, char **path, t_env *env);
int	create_tree(t_tree *tree);
int	my_cd(char **cmd, t_all *all);
int	my_setenv(char **cmd, t_all *all);
int	my_unsetenv(char **cmd, t_all *all);
int	my_exit_and_env(char **cmd, t_all *all);
char	*epurstr(char *str);
char	*get_next_line(int fd);
char	*my_getenv(char **env, char *str);
char	**create_env(char **ae, int i);
char	**my_str_to_wordtab(char *str, char opt);

#endif /* !_42SH_H_ */
