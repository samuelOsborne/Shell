##
## Makefile for 42sh in /media/villen_l/home/villen_l/rendu/Tek1Semestre2/Shell/PSU_2015_42sh
##
## Made by Lucas Villeneuve
## Login   <villen_l@epitech.net>
##
## Started on  Wed May 11 16:00:21 2016 Lucas Villeneuve
## Last update Fri Jun  3 18:15:49 2016 Lucas Villeneuve
##

NAME	=	42sh

SRC	=	src/main.c			\
		src/get_next_line.c		\
		src/my_str_to_wordtab.c		\
		src/my_str_to_wordpipe.c	\
		src/my_print.c			\
		src/error.c			\
		src/my_free.c			\
		src/epurstr.c			\
		src/my_env.c			\
		src/create_tree.c		\
		src/my_exec.c			\
		src/my_getenv.c			\
		src/find_type_cmd.c		\
		src/builtins.c			\
		src/my_exit.c			\
		src/my_getnbr.c			\
		src/manage_tab_env.c		\
		src/my_echo.c			\
		src/my_echo_dollar.c		\
		src/my_cd.c			\
		src/my_pipe.c			\
		src/create_cmd_pipe.c		\
		src/exec_pipe.c			\
		src/manage_pipe.c		\
		src/check_pipe.c		\
		src/count_wordpipe.c		\
		src/my_ctrl_c.c			\
		src/loop_pipe.c			\
		src/command_not_found.c		\
		src/get_spec.c			\
		src/exec_tree.c			\
		src/alias_list.c		\
		src/init_rc.c			\
		src/merge_alias.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-I include -W -Wall -Wextra

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
