/*
** 42sh.h for 42sh in /home/escorn_t/Rendu/PSU/PSU_2015_42sh
**
** Made by escorn_t
** Login   <escorn_t@epitech.net>
**
** Started on  Wed May 11 13:26:46 2016 escorn_t
** Last update Sun Jun  5 12:52:24 2016 Lucas Villeneuve
*/

#ifndef _42SH_H_
# define _42SH_H_

# define HEAD(fd, s)	if (write(fd, s, strlen(s)) != strlen(s)) {return (1);}

typedef struct		s_tree
{
  char			*spec;
  char			*cmd;
  struct s_tree		**next;
}			t_tree;

typedef struct		s_pipe
{
  char			**tab;
  int			type;
}			t_pipe;

typedef	struct		s_env
{
  int			size;
  char			**tab;
}			t_env;

typedef struct		s_cd
{
  char			*old;
  char			*pwd;
}			t_cd;

typedef struct		s_fd
{
  int			start;
  int			end;
  int			mode;
}			t_fd;

typedef struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_all
{
  t_alias		*alias;
  t_env			env;
  t_cd			cd;
  t_tree		*tree;
  char			**path;
  int			tty;
  int			lock_prompt;
  int			status;
}			t_all;

void	ini_prompt();
void	free_prompt();
void	error_malloc();
void	free_cd(t_cd cd);
void	my_putchar(char c);
void	sig_finder(int sig);
void	free_env(t_env env);
void	free_tab(char **tab);
void	my_putstr(char *str);
void	init_all(t_all *all);
void	print_env(t_env *env);
void	my_put_err(char *str);
void	my_putchar_err(char c);
void	free_path(char **path);
void	free_tree(t_tree *tree);
void	error_status(int status);
void	error_command_pipe(char *str);
void	my_cd(t_all *all, char **cmd);
void	my_pipe(char **tab, t_all *all);
void	my_echo(char **cmd, t_all *all);
void	get_spec(t_tree *tree, int cmpt);
void	my_simple_exit(char **cmd, t_all *all);
void	put_alias_in_list(t_all *all, t_alias *new);
void	manage_end_pipe(int end, t_pipe *cmd, int j);
void	my_setenv(char **cmd, t_env *env, t_all *all);
void	my_unsetenv(char **cmd, t_env *env, t_all *all);
void	my_loop_pipe(char **tab, t_all *all, t_pipe *cmd);
void	my_advanced_exit(char **cmd, t_all *all, int ret);
void	my_simple_exec(t_all *all, char **cmd, char **path, t_env *env);
void	my_exec_pipe(char **cmd, char **path, t_env *env, t_all *all);
void	manage_start_pipe(t_fd *st_end, t_pipe *cmd, int j, t_all *all);
int	is_dir(char *cmd);
int	error_pipe(char c);
int	alphanum(char *str);
int	init_rc(t_all *all);
int	my_getnbr(char *str);
int	check_pipe(char *str);
int	is_alias_valid(char *s);
int	count_nb_pipe(char **tab);
int	create_tree(t_tree *tree);
int	check_for_star(char *str);
int	count_nb_args(char **tab);
int	create_exec_tree(t_tree *tree);
int	count_args_wordpipe(char *str);
int	read_in_rc(t_all *all, char *s);
int	check_builtin(char **cmd, t_all *all);
int	my_getenv_line(char **env, char *str);
int	my_cd_builtin(char **cmd, t_all *all);
int	launch_exec(t_tree *tree, t_all *all);
int	my_exit_env_echo(char **cmd, t_all *all);
int	my_setenv_builtin(char **cmd, t_all *all);
int	my_unsetenv_builtin(char **cmd, t_all *all);
int	launch_condition(t_all *all, char *spec, int pos);
int	check_dollar(char **str, int i, int j, t_all *all);
char	*get_alias(char *s);
char	*epurstr(char *str);
char	*get_next_line(int fd);
char	*get_alias_cmd(char *s);
char	*permission_denied(char *cmd);
char	*command_not_found(char *cmd);
char	*my_getenv(char **env, char *str);
char	*find_bin(char **path, char **cmd);
char	*find_bin_without_path(char **cmd);
char	*get_prompt(char *s);
char	*merge_alias(t_all *all, char *cmd);
char	**no_match(char **tab);
char	**create_env(char **ae, int i);
char	**my_str_to_wordpipe(char *str);
char	**find_type_cmd(char **tab, t_all *all);
char	**my_str_to_wordtab(char *str, char opt);
char	**my_glob(char *path, char **tab, int pos);
char	**recreate_tab_unset(char **ae, int i, int del);
char	**recreate_tab_set(char **cmd, char **ae, int i);
t_pipe	*create_cmd_pipe(char **tab);

#endif /* !_42SH_H_ */
