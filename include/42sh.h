/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Wed Jun  1 15:43:29 2016 escorn_t
*/

#ifndef _42SH_H_
# define _42SH_H_

typedef struct  s_tree
{
  char		*spec;
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
  int		mode;
}		t_fd;

typedef struct	s_all
{
  t_env		env;
  t_cd		cd;
  t_tree	*tree;
  char		**path;
  int		tty;
  int		status;
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
void	manage_end_pipe(int end, t_pipe *cmd, int j);
void	my_loop_pipe(char **tab, t_all *all, t_pipe *cmd);
void	my_advanced_exit(char **cmd, t_all *all, int ret);
void	my_simple_exec(t_all *all, char **cmd, char **path, t_env *env);
void	my_exec_pipe(char **cmd, char **path, t_env *env, t_all *all);
void	manage_start_pipe(t_fd *st_end, t_pipe *cmd, int j, t_all *all);
void	sig_finder(int sig);
void	get_spec(t_tree *tree, int cmpt);
int	is_dir(char *cmd);
int	error_pipe(char c);
int	my_getnbr(char *str);
int	check_pipe(char *str);
int	count_nb_pipe(char **tab);
int	create_tree(t_tree *tree);
int	count_args_wordpipe(char *str);
int	check_builtin(char **cmd, t_all *all);
int	my_getenv_line(char **env, char *str);
int	my_cd_builtin(char **cmd, t_all *all);
int	my_exit_env_echo(char **cmd, t_all *all);
int	my_setenv_builtin(char **cmd, t_all *all);
int	my_unsetenv_builtin(char **cmd, t_all *all);
int	check_dollar(char **str, int i, int j, t_all *all);
int	create_exec_tree(t_tree *tree);
int	launch_exec(t_tree *tree, t_all *all);
int	launch_condition(t_all *all, char *spec, int pos);
char	*epurstr(char *str);
char	*got_right(char *cmd);
char	*get_next_line(int fd);
char	*command_not_found(char *cmd);
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
