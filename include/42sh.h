/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Thu May 26 18:17:09 2016 Arnaud Costa
*/

#ifndef _42SH_H_
# define _42SH_H_

typedef struct  s_tree
{
  char		*cmd;
  struct s_tree	**next;
}		t_tree;

typedef struct	s_pipe
{
  char		**tab;
  int		type;
}		t_pipe;

typedef	struct	s_env
{
  int		size;
  char		**tab;
}		t_env;

typedef struct	s_cd
{
  char		*old;
  char		*pwd;
}		t_cd;

typedef struct	s_fd
{
  int		start;
  int		end;
}		t_fd;

typedef struct	s_all
{
  t_env		env;
  t_cd		cd;
  t_tree	*tree;
  char		**path;
  int		tty;
}		t_all;

void	error_malloc();
void	free_cd(t_cd cd);
void	my_putchar(char c);
void	free_env(t_env env);
void	free_tab(char **tab);
void	my_putstr(char *str);
void	print_env(t_env *env);
void	my_put_err(char *str);
void	my_putchar_err(char c);
void	free_path(char **path);
void	free_tree(t_tree *tree);
void	my_cd(t_all *all, char **cmd);
void	my_pipe(char **tab, t_all *all);
void	my_echo(char **cmd, t_all *all);
void	my_setenv(char **cmd, t_env *env);
void	my_unsetenv(char **cmd, t_env *env);
void	find_type_cmd(char **tab, t_all *all);
void	my_simple_exit(char **cmd, t_all *all);
void	manage_end_pipe(int start, t_pipe *cmd, int j);
void	manage_start_pipe(int start, t_pipe *cmd, int j);
void	my_exec_pipe(char **cmd, char **path, t_env *env);
void	my_advanced_exit(char **cmd, t_all *all, int ret);
void	my_simple_exec(char **cmd, char **path, t_env *env);
void	manage_start_redir(int start, int end, t_pipe *cmd, t_all *all);
void	sig_finder(int sig);
int	error_pipe(char c);
int	my_getnbr(char *str);
int	check_pipe(char *str);
int	count_nb_pipe(char **tab);
int	create_tree(t_tree *tree);
int	count_args_wordpipe(char *str);
int	my_getenv_line(char **env, char *str);
int	my_cd_builtin(char **cmd, t_all *all);
int	my_exit_env_echo(char **cmd, t_all *all);
int	my_setenv_builtin(char **cmd, t_all *all);
int	my_unsetenv_builtin(char **cmd, t_all *all);
int	check_dollar(char **str, int i, int j, t_all *all);
char	*epurstr(char *str);
char	*get_next_line(int fd);
char	*my_getenv(char **env, char *str);
char	*find_bin(char **path, char **cmd);
char	*find_bin_without_path(char **cmd);
char	**create_env(char **ae, int i);
char	**my_str_to_wordpipe(char *str);
char	**my_str_to_wordtab(char *str, char opt);
char	**recreate_tab_unset(char **ae, int i, int del);
char	**recreate_tab_set(char **cmd, char **ae, int i);
t_pipe	*create_cmd_pipe(char **tab);

#endif /* !_42SH_H_ */
